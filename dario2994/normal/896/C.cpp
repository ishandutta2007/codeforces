#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 100100;
struct Node {
    LL val;
    LL len;
    Node* next;
    Node* prev;
    Node() : next(nullptr), prev(nullptr) {}
    Node(LL val, LL len) : val(val), len(len), next(nullptr), prev(nullptr) {}
};
Node* first_node;


vector<pair<LL,LL>> GetRangeValues(int l, int r) { // [l, r]
    vector<pair<LL,LL>> res;
    Node* curr = first_node;
    while (r >= 0) {
        int count = min(r+1, (int)curr->len) - max(0, l);
        if (count > 0) res.push_back({curr->val, count});
        l -= curr->len;
        r -= curr->len;
        curr = curr->next;
    }
    return res;
}

void Split(int pos) {
    Node* curr = first_node;
    while (pos >= curr->len) {
        pos -= curr->len;
        curr = curr->next;
    }
    if (pos == curr->len-1) return;
    Node* new_node = new Node(curr->val, curr->len - (pos+1));
    curr->len = pos+1;
    new_node->next = curr->next;
    if (curr->next) curr->next->prev = new_node;
    new_node->prev = curr;
    curr->next = new_node;
}

Node* Find(int pos) {
    Node* curr = first_node;
    while (pos >= curr->len) {
        pos -= curr->len;
        curr = curr->next;
    }
    return curr;
}

void Assign(int l, int r, LL x) { // [l, r]
    Split(l-1);
    Split(r);
    Node* A = Find(l);
    Node* B = Find(r);
    A->next = B->next;
    if (A->next) A->next->prev = A;
    A->val = x;
    A->len = r-l+1;
}

void Sum(int l, int r, LL x) {
    Split(l-1);
    Split(r);
    Node* A = Find(l);
    Node* B = Find(r);
    Node* curr = A;
    while (curr != B->next) {
        curr->val += x;
        curr = curr->next;
    }
}

LL xmin(int l, int r, int k) {
    auto vec = GetRangeValues(l, r);
    sort(vec.begin(), vec.end());
    for (auto pp : vec) {
        if (k <= pp.second) return pp.first;
        k -= pp.second;
    }
    assert(0);
    return -1;
}

LL modpow(LL b, LL e, LL mod) {
    if (e == 1) return b % mod;
    if (e % 2) return (b * modpow((b*b)%mod, e/2, mod)) % mod;
    else return modpow((b*b)%mod, e/2, mod);
}

LL powsum(int l, int r, LL x, LL y) {
    const auto& vec = GetRangeValues(l, r);
    LL res = 0;
    for (auto pp : vec) {
        res = (res + pp.second * modpow(pp.first % y, x, y)) % y;
    }
    assert(res >= 0);
    return res;
}


LL n, seed, vmax;
LL rnd() {
    LL ret = seed;
    seed = (seed * 7ll + 13ll) % 1000000007ll;
    return ret;
}

LL init_val[MAXN];
void InitVal() {
    for (int i = 1; i <= n; i++) init_val[i] = (rnd() % vmax) + 1;
    first_node = new Node(0, 0);
    Node* last_node = first_node;
    for (int i = 0; i < n+5; i++) {
        Node* curr = new Node(init_val[i], 1);
        curr->prev = last_node;
        last_node->next = curr;
        last_node = curr;
    }
    // for (int i = 1; i <= n; i++) cout << init_val[i] << " ";
    // cout << endl;
}

void PrintStatus() {
    // Node* curr = first_node;
    // while (curr != nullptr) {
        // cout << "{" << curr->val << ", " << curr->len << "}; ";
        // curr = curr->next;
    // }
    Node* curr = first_node;
    while (curr != nullptr) {
        for (int i = 0; i < curr->len; i++) cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int m;
    cin >> n >> m >> seed >> vmax;
    
    InitVal();
    for (int i = 1; i <= m; i++) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        int x, y;
        if (l > r) swap(l, r);

        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % vmax) + 1;

        if (op == 4) y = (rnd() % vmax) + 1;

        // cout << op << " " << l << " " << r << " " << x << " ";
        // if (op == 4) cout << y;
        // cout << "\n";

        if (op == 1) Sum(l, r, x);
        if (op == 2) Assign(l, r, x);
        if (op == 3) cout << xmin(l, r, x) << "\n";
        if (op == 4) cout << powsum(l, r, x, y) << "\n";
        // PrintStatus();
    }
}