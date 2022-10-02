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

const int MAXN = 101000;
unordered_set<int> aa[MAXN];

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int v = 1; v <= N; v++) aa[v].clear();
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        aa[u].insert(v);
        aa[v].insert(u);
    }
    if (K >= 500) {
        cout << -1 << "\n";
        return;
    }
    if (K == 1) {
        cout << 2 << "\n";
        cout  << 1 << "\n";
        return;
    }
    typedef pair<int,int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int v = 1; v <= N; v++) {
        pq.push({aa[v].size(), v});
    }
    while (!pq.empty()) {
        auto pp = pq.top();
        pq.pop();
        int v = pp.second;
        if (aa[v].empty()) continue;
        // dbg(v, SZ(aa[v]));
        if (SZ(aa[v]) >= K) {
            vector<int> S;
            for (int v = 1; v <= N; v++) {
                if (SZ(aa[v]) >= K) S.push_back(v);
            }
            cout << 1 << " " << S.size() << "\n";
            for (int s: S) cout << s << " ";
            cout << "\n";
            return;
        }
        if (SZ(aa[v]) == K-1) {
            // check clique
            bool works = true;
            vector<int> aaa(aa[v].begin(), aa[v].end());
            for (int i = 0; i < K-1 && works; i++) for (int j = i+1; j < K-1; j++) {
                if (!aa[aaa[i]].count(aaa[j])) {
                    works = false;
                    break;
                }
            }
            if (works) {
                cout << 2 << "\n";
                cout << v << " ";
                for (int a: aa[v]) cout << a << " ";
                cout << "\n";
                return;
            }
        }
        for (int a: aa[v]) {
            aa[a].erase(v);
            pq.push({SZ(aa[a]), a});
        }
        aa[v].clear();
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}