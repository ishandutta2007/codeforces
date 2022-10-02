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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define endl "\n";

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// This should not compile if used.
const int MAXN = 200010;
const int MAXK = 5;
LL c[MAXN][MAXK];
LL s[MAXN][MAXK];
LL cc[MAXN];
LL ss[MAXN];
LL ris[MAXN]; 
vector<int> aa[MAXN];
int K;



LL sx[MAXK];
LL cx[MAXK];
LL qx[MAXK][MAXK];
LL zx[MAXK][MAXK];

void dfs(int v, int f) {
    c[v][0] = 1; // himself
    for (int a : aa[v]) {
        if (a == f) continue;
        dfs(a, v);
        for (int t = 0; t < K; t++) {
            int q = (t+K-1)%K;
            c[v][t] += c[a][q];
            s[v][t] += s[a][q];
            if (t == 0) s[v][t] += c[a][q];
        }
    }
    for (int t = 0; t < K; t++) {
        cc[v] += c[v][t];
        ss[v] += s[v][t];
    }

    LL loc_sum = 0;
    for (int a : aa[v]) {
        if (a == f) continue;
        loc_sum += ss[a];
    }

    LL ris1 = loc_sum + cc[v] - 1; // path from root
    LL ris2 = 0;
    LL ris3 = 0;

    for (int t1 = 0; t1 < K; t1++) {
        sx[t1] = 0;
        cx[t1] = 0;
        for (int a : aa[v]) {
            if (a == f) continue;
            sx[t1] += s[a][t1];
            cx[t1] += c[a][t1];
        }
    }
    
    for (int t1 = 0; t1 < K; t1++) {
        for (int t2 = 0; t2 < K; t2++) {
            qx[t1][t2] = 0;
            zx[t1][t2] = 0;
            for (int a : aa[v]) {
                if (a == f) continue;
                qx[t1][t2] += c[a][t1]*c[a][t2];
                zx[t1][t2] += s[a][t1]*c[a][t2];
            }
            ris2 += sx[t1]*cx[t2] - zx[t1][t2];
            LL coef;
            if (t1 + t2 + 2 <= K) coef = 1;
            else coef = 2;
            ris3 += coef * (cx[t1]*cx[t2] - qx[t1][t2]);
        }
    }
    // assert(ris3%2 == 0);

    ris3 /= 2;
    ris[v] = ris1 + ris2 + ris3;
} 

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N >> K;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        aa[a].push_back(b);
        aa[b].push_back(a);
    }
    dfs(0, -1);
    
    LL res = 0;
    for (int i = 0; i < N; i++) {
        res += ris[i];
    }
    cout << res;
}