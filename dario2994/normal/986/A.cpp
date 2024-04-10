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
const int MAXK = 105;
vector<int> aa[MAXN];
int A[MAXN];
int dist[MAXK][MAXN];
int N, M, K, S;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N >> M >> K >> S;
    for (int i = 0; i < N; i++) cin >> A[i+1];
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    for (int it = 1; it <= K; it++) {
        queue<int> q;
        for (int i = 1; i <= N; i++) {
            dist[it][i] = INF;
            if (A[i] == it) {
                dist[it][i] = 0;
                q.push(i);
            }
        }
        assert(!q.empty());
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int a : aa[v]) {
                if (dist[it][a] < INF) continue;
                dist[it][a] = dist[it][v]+1;
                q.push(a);
            }
        }
    }
    vector<int> dd(K);
    for (int v = 1; v <= N; v++) {
        for (int i = 1; i <= K; i++) dd[i-1] = dist[i][v];
        sort(dd.begin(), dd.end());
        int sum = 0;
        // dbg_var(dd);
        for (int i = 0; i < S; i++) sum += dd[i];
        cout << sum << " ";
    }
    cout << "\n";
}