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


bool flag[1<<20]; // resetting
int fen[1<<20];

void deflag(int v) {
    if (flag[v]) {
        flag[v] = 0;
        fen[2*v] = 0;
        fen[2*v+1] = 0;
        flag[2*v] = 1;
        flag[2*v+1] = 1;
    }
}

void reset(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return;
    if (a <= l and r <= b) {
        flag[v] = 1;
        fen[v] = 0;
        return;
    }
    deflag(v);
    int m = (l+r)/2;
    reset(2*v, l, m, a, b);
    reset(2*v+1, m+1, r, a, b);
    fen[v] = fen[2*v] + fen[2*v+1];
}

int get(int v, int l, int r, int a, int b) {
    // dbg(v, l, r, a, b);
    if (r < a or b < l) return 0;
    if (a <= l and r <= b) return fen[v];
    deflag(v);
    int m = (l+r)/2;
    return get(2*v, l, m, a, b) + get(2*v+1, m+1, r, a, b);
}



vector<pair<int,int>> ans;
void match(int x, int y) {
    y--;
    assert(x <= y);
    // dbg(x, y);
    // int fen_bef = fen[1];
    int l = get(1, 0, (1<<19)-1, 0, x);
    int r = get(1, 0, (1<<19)-1, 0, y);
    ans.push_back({l, r});
    reset(1, 0, (1<<19)-1, x, y);
    // int fen_aft = fen[1];
    // dbg(x, y, l, r, fen_bef, fen_aft);
    // assert(fen_bef-fen_aft == r-l+1);
}

vector<int> good[2][26];
void solve() {
    for (int i = 0; i < 26; i++) good[0][i].clear(), good[1][i].clear();
    ans.clear();
    string SS;
    cin >> SS;
    int N = SS.size();
    vector<int> S(N);
    for (int i = 0; i < N; i++) S[i] = SS[i]-'a';
    for (int i = 0; i < N; i++) {
        int v = i + (1<<19);
        while (v != 0) {
            fen[v]++;
            v /= 2;
        }
    }

    vector<int> cnt(26, 0);
    set<int> pos;
    vector<int> pos_vec;
    for (int i = 0; i < N-1; i++) {
        if (S[i] == S[i+1]) {
            pos.insert(i+1);
            pos_vec.push_back(i+1);
            cnt[S[i]]++;
        }
    }
    
    for (int i = 0; i < SZ(pos_vec)-1; i++) {
        if (S[pos_vec[i]] != S[pos_vec[i+1]]) {
            good[0][S[pos_vec[i]]].push_back(pos_vec[i]);
            good[1][S[pos_vec[i+1]]].push_back(pos_vec[i+1]);
        }
    }

    
    while (!pos.empty()) {
        int let = 0;
        for (int i = 1; i < 26; i++) {
            if (cnt[i] > cnt[let]) let = i;
        }
        // dbg(let);
        // dbg(good[0][let], good[1][let]);
        if (!good[0][let].empty()) {
            // dbg(let, good[0][let]);
            int l = good[0][let].back();
            good[0][let].pop_back();
            if (!pos.count(l)) continue;
            auto it = pos.upper_bound(l);
            if (it == pos.end()) continue;
            int r = *it;
            if (S[l] == S[r]) continue;
            // matching!
            match(l, r);
            pos.erase(l);
            pos.erase(r); // removing both
            cnt[S[l]]--;
            cnt[S[r]]--;
            // add to good!
            auto aft = pos.lower_bound(l);
            if (aft == pos.end() or aft == pos.begin()) continue;
            auto bef = prev(aft);

            int a = *bef, b = *aft;
            if (S[a] != S[b]) {
                good[0][S[a]].push_back(a);
                good[1][S[b]].push_back(b);
            }
        } else if (!good[1][let].empty()) {
            int r = good[1][let].back();
            // dbg(r);
            good[1][let].pop_back();
            if (!pos.count(r)) continue;
            auto it = pos.lower_bound(r);
            if (it == pos.begin()) continue;
            int l = *prev(it);
            // dbg(l);
            if (S[l] == S[r]) continue;
            // dbg(l, r);
            // matching!
            match(l, r);
            pos.erase(l);
            pos.erase(r); // removing both
            cnt[S[l]]--;
            cnt[S[r]]--;
            // add to good!
            auto aft = pos.lower_bound(l);
            if (aft == pos.end() or aft == pos.begin()) continue;
            auto bef = prev(aft);

            int a = *bef, b = *aft;
            if (S[a] != S[b]) {
                good[0][S[a]].push_back(a);
                good[1][S[b]].push_back(b);
            }
        } else {// last part!
            vector<int> pos_vec;
            for (auto x: pos) pos_vec.push_back(x);
            // dbg(pos_vec);
            reverse(pos_vec.begin(), pos_vec.end());
            for (int x: pos_vec) match(x, N);
            break;
        }
    }
    ans.push_back({1, fen[1]}); // finish

    cout << ans.size() << "\n";
    for (auto pp: ans) {
        cout << pp.first << " " << pp.second << "\n";
        // assert(pp.first <= pp.second);
        // dbg(pp);
        // for (int i = pp.first; i < pp.second; i++) {
            // assert(S[i] != S[i-1]);
        // }
        // vector<int> T;
        // for (int i = 0; i < pp.first-1; i++) T.push_back(S[i]);
        // for (int i = pp.second; i < SZ(S); i++) T.push_back(S[i]);
        // S = T;
    }
    // assert(S.empty());

    for (int i = 0; i < min(2*N, 1<<18); i++) {
        int v = i + (1<<19);
        while (v != 0) {
            fen[v] = 0, flag[v] = 0;
            v /= 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}