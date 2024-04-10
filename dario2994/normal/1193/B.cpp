#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXL = 18;

struct SegTree {
    LL val;
    LL flag;
    SegTree* l, *r;
    SegTree(): val(0), flag(0), l(nullptr), r(nullptr) {}
    ~SegTree() {
        if (l != nullptr) delete l;
        if (r != nullptr) delete r;
    }
    bool is_leaf() { return l == nullptr; }
    void Expand() {
        if (is_leaf()) {
            l = new SegTree();
            r = new SegTree();
        }
        if (flag) {
            l->val += flag, l->flag += flag;
            r->val += flag, r->flag += flag;
            flag = 0;
        }
    }
};

void Debug(int v, int a, int b, SegTree *S) {
    cout << v << " (" << a << " " << b << "): " << S->val << " " << S->flag;
    if (S->is_leaf()) cout << " LEAF\n";
    else {
        cout << "\n";
        int m = (a+b)/2;
        Debug(2*v, a, m, S->l);
        Debug(2*v+1, m+1, b, S->r);
    }
}

void Join(SegTree* S, SegTree* T) { // WRONG!
    if (!T->is_leaf()) {
        S->Expand();
        Join(S->l, T->l);
        Join(S->r, T->r);
    }
    S->val += T->val;
    S->flag += T->flag;
}

void Update(int v, LL val, int a, int b, SegTree* S) {

    // cout.flush();
    // dbg(v, val, a, b, S->is_leaf(), S->val);
    // cerr.flush();
    if (b < v) return; // out of range
    if (S->is_leaf() and S->val >= val) return; // nothing to change
    if (S->val < val and v <= a) { // change everything
        S->val = val;
        S->flag = val;
        S->l = nullptr, S->r = nullptr;
        return;
    }
    S->Expand();
    S->val = max(S->val, val); // for sure
    int m = (a+b)/2;
    if (S->l->val < val) Update(v, val, m+1, b, S->r);
    Update(v, val, a, m, S->l);
}

LL GetMax(int v, int a, int b, SegTree* S) {
    if (v < a) return 0;
    if (b <= v or S->is_leaf()) return S->val;
    S->Expand();
    int m = (a+b)/2;
    LL res = 0;
    res = max(GetMax(v, a, m, S->l), GetMax(v, m+1, b, S->r)); // can be optimized
    return res;
}


const int MAXN = 100100;
int sz[MAXN];
vector<int> aa[MAXN];
int d[MAXN];
LL w[MAXN];
SegTree* compute(int v) {
    LL spec = 0;
    int curr_sz = 1;
    SegTree* res = new SegTree();
    for (int a : aa[v]) {
        SegTree* ris = compute(a);
        if (d[v]) spec += GetMax(d[v], 0, (1<<MAXL)-1, ris);
        // cout << v << " " << a << endl;
        // Debug(1, 0, (1<<MAXL)-1, ris);
        if (sz[a] > curr_sz) swap(ris, res);
        // cout << v << " " << a << endl;
        // Debug(1, 0, (1<<MAXL)-1, res);
        Join(res, ris);
        // cout << v << " " << a << endl;
        // Debug(1, 0, (1<<MAXL)-1, res);
        
        delete ris;
        curr_sz += sz[a];
    }
    // cout << v << endl;
    // Debug(1, 0, (1<<MAXL)-1, res);
    
    sz[v] = curr_sz;
    if (d[v]) {
        spec += w[v];
        Update(d[v], spec, 0, (1<<MAXL)-1, res); // hard to implement
    }
    // cout << v << endl;
    // Debug(1, 0, (1<<MAXL)-1, res);
    // cout << v << " " << res->val << " " << GetMax(0, 0, (1<<MAXL)-1, res) << endl;
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        aa[p].push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int v;
        cin >> v;
        cin >> d[v] >> w[v];
    }
    cout << compute(1)->val << "\n";
}