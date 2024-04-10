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

struct pt {
    int x, y;
};

ostream& operator <<(ostream& out, pt A) {
    out << "(" << A.x << "," << A.y << ")";
    return out;
}

const int MAXN = 1<<22;
int ff[2*MAXN];
int memo[2*MAXN];

void Propagate(int v) {
    if (memo[v] == 0) return;
    ff[2*v] += memo[v];
    ff[2*v+1] += memo[v];
    memo[2*v] += memo[v];
    memo[2*v+1] += memo[v];
    memo[v] = 0;
}

void Add(int v, int l, int r, int a, int b, int q) {
    if (b < l or r < a) return;
    if (a <= l and r <= b) {
        ff[v] += q;
        memo[v] += q;
        return;
    }
    Propagate(v);
    int m = (l+r)/2;
    Add(2*v, l, m, a, b, q);
    Add(2*v+1, m+1, r, a, b, q);
    ff[v] = max(ff[2*v], ff[2*v+1]);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, r;
    cin >> N >> r;
    r *= 2;
    vector<pt> P(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P[i].x = x+y,
        P[i].y = x-y + 2e6;
    }
    sort(P.begin(), P.end(), [&](pt A, pt B) { return (A.x == B.x)?(A.y > B.y):(A.x > B.x); });
    // dbg(P);
    queue<pt> to_remove;
    int res = 0;
    for (pt p : P) {
        // dbg(p);
        to_remove.push(p);
        // dbg(p.y);
        Add(1, 0, MAXN-1, p.y, min(MAXN-1, p.y+r), 1);
        while (!to_remove.empty() and to_remove.front().x > p.x + r) {
            pt q = to_remove.front();
            // dbg(q);
            to_remove.pop();
            
            // dbg(q.y);
            Add(1, 0, MAXN-1, q.y, min(MAXN-1, q.y+r), -1);
        }
        // dbg_arr(ff, 16);
        int ris = ff[1];
        res = max(res, ris);
    }
    cout << res << "\n";
}