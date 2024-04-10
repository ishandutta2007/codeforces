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

const int MAXN = 1100;
int N;
map<int, map<int,int>> horiz, vert;
LL xxx[MAXN], yyy[MAXN];
LL T;
int cc = 0;
int comp[MAXN];
bool visited[MAXN];

vector<pair<int, LL>> aa(LL x, LL y) {
    vector<pair<int,LL>> vec;
    auto it1 = horiz[y].upper_bound(x);
    auto it2 = horiz[y].lower_bound(x);
    if (it1 != horiz[y].end()) {
        LL new_x = it1->first;
        vec.push_back({it1->second, llabs(new_x-x)});
    }
    if (it2 != horiz[y].begin()) {
        it2 = prev(it2);
        LL new_x = it2->first;
        vec.push_back({it2->second, llabs(x-new_x)});
    }

    auto it3 = vert[x].upper_bound(y);
    auto it4 = vert[x].lower_bound(y);
    if (it3 != vert[x].end()) {
        LL new_y = it3->first;
        vec.push_back({it3->second, llabs(y-new_y)});
    }
    if (it4 != vert[x].begin()) {
        it4 = prev(it4);
        LL new_y = it4->first;
        vec.push_back({it4->second, llabs(y-new_y)});
    }
    return vec;
}

void dfs(int v) {
    comp[v] = cc;
    visited[v] = true;
    const auto& vec = aa(xxx[v], yyy[v]);
    for (const auto& pp: vec) {
        if (pp.second > T) continue;
        int a = pp.first;
        if (!visited[a]) dfs(a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;
    set<int> xx, yy;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        xxx[i] = x, yyy[i] = y;
        horiz[y][x] = i;
        vert[x][y] = i;
        xx.insert(x), yy.insert(y);
    }
    
    vector<vector<pair<int,LL>>> possible;
    for (int x: xx) for (int y: yy) {
        if (horiz[y].count(x)) continue;
        possible.push_back(aa(x, y));
    }
    for (int x: xx) {
        const auto& v = vert[x];
        for (auto it = v.begin(); next(it) != v.end(); it++) {
            LL y1 = it->first;
            LL y2 = next(it)->first;
            int id1 = it->second;
            int id2 = next(it)->second;
            vector<pair<int,LL>> vec;
            LL dist = llabs(y1-y2);
            if (dist == 1) continue;
            vec.push_back({id1, dist/2});
            vec.push_back({id2, dist - dist/2});
            possible.push_back(vec);
        }
    }
    for (int y: yy) {
        const auto& v = horiz[y];
        for (auto it = v.begin(); next(it) != v.end(); it++) {
            LL y1 = it->first;
            LL y2 = next(it)->first;
            int id1 = it->second;
            int id2 = next(it)->second;
            vector<pair<int,LL>> vec;
            LL dist = llabs(y1-y2);
            if (dist == 1) continue;
            vec.push_back({id1, dist/2});
            vec.push_back({id2, dist - dist/2});
            possible.push_back(vec);
        }
    }

    LL l = 1;
    LL r = 1e12;
    // LL l = 2;
    // LL r = 3;

    bool check_me[4];
    while (l < r) {
        LL m = (l+r)/2;
        T = m;
        cc = 0;
        for (int i = 0; i < N; i++) visited[i] = false;
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            dfs(i);
            cc++;
        }
        if (cc > 4) {
            l = m+1;
            continue;
        }
        if (cc == 1) {
            r = m;
            continue;
        }
        
        // dbg(cc);
        // dbg_arr(comp, N);
        bool connected = false;
        for (auto& vec: possible) {
            if (SZ(vec) < cc) continue;
            for (int i = 0; i < cc; i++) check_me[i] = false;
            for (auto pp: vec) {
                if (pp.second <= T) check_me[comp[pp.first]] = true;
            }
            bool ok = true;
            for (int i = 0; i < cc; i++) ok &= check_me[i];
            if (ok) {
                connected = true;
                break;
            }
        }
        if (connected) r = m;
        else l = m+1;
    }

    if (l > 1e10) cout << -1 << "\n";
    else cout << l;
}