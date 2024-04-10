#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

const int MAXN = 100100;
int c[2][MAXN];
vector<int> comp[2][MAXN];

multiset<pair<int,int>> val1, val2;
map<pair<int,int>,set<int>> memo;

void remove(int x) {
    pair<int,int> id = {c[0][x], c[1][x]};
    // dbg("REM", x, id);
    memo[id].erase(x);
    val1.erase(val1.find(id));
    swap(id.first, id.second);
    val2.erase(val2.find(id)); 
}

void add(int x) {
    pair<int,int> id = {c[0][x], c[1][x]};
    // dbg("ADD", x, id);
    memo[id].insert(x);
    val1.insert(id);
    swap(id.first, id.second);
    val2.insert(id); 
}

void join(int it, int u, int v) {
    u = c[it][u];
    v = c[it][v];
    assert(u != v);
    // dbg(it, u, v);
    if (comp[it][u].size() < comp[it][v].size()) swap(u, v);
    for (int x: comp[it][v]) {
        remove(x);
        comp[it][u].push_back(x);
        c[it][x] = u;
        add(x);
    }
    comp[it][v].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    for (int i = 1; i <= n; i++) {
        c[0][i] = c[1][i] = i;
        comp[0][i] = comp[1][i] = {i};
        val1.insert({i, i});
        val2.insert({i, i});
        memo[{i,i}].insert(i);
    }
    
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        join(0, a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        join(1, a, b);
    }
    // for (int i = 1; i <= n; i++) cout << c[0][i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << c[1][i] << " ";
    // cout << endl;
    // return 0;

    vector<pair<int,int>> edges;
    while (m1 < n-1 and m2 < n-1) {
        vector<pair<int,int>> poss = {
            *val1.begin(),
            *val1.rbegin(),
            *val2.begin(),
            *val2.rbegin()
        };
        swap(poss[2].first, poss[2].second);
        swap(poss[3].first, poss[3].second);
        // dbg(poss);
        bool works = false;
        for (int i = 0; i < 4 and !works; i++) for (int j = i+1; j < 4; j++) {
            auto pp1 = poss[i], pp2 = poss[j];
            if (pp1.first != pp2.first and pp1.second != pp2.second) {
                // dbg(pp1, pp2);
                int a = *memo[pp1].begin();
                int b = *memo[pp2].begin();
                join(0, a, b);
                join(1, a, b);
                edges.push_back({a, b});
                works = true;
                break;
            }
        }
        assert(works);
        m1++, m2++;
    }

    cout << edges.size() << "\n";
    for (auto pp: edges) cout << pp.first << " " << pp.second << "\n";
}