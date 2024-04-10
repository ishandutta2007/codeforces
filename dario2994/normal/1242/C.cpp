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

const int MAXK = 15;

vector<vector<int>> cycles[1<<MAXK];
bool is_cycle[1<<MAXK];
set<int> visited;

bool din[1<<MAXK];
int debugging = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int K;
    cin >> K;
    vector<vector<LL>> vec(K);
    vector<LL> sums(K, 0);
    LL sum = 0;
    unordered_map<int,int> MAPPA;
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        vec[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
            sums[i] += vec[i][j];
            MAPPA[vec[i][j]] = i;
        }
    }
    if (sum%K != 0) {
        cout << "No\n";
        return 0;
    }
    sum /= K;

    // dbg(sum, sums);

    int NAAAN = 1e9 + 3243;
    visited.insert(NAAAN);
    for (int i = 0; i < K; i++) {
        function<int(int)> get_next = [&](int it) {
            int z = MAPPA[it];
            LL a = sum -sums[z] + it;
            if (llabs(a) > NAAAN) return NAAAN;
            if (!MAPPA.count(a)) return NAAAN;
            return (int)a;
        };
        for (LL c : vec[i]) {
            // dbg(vec[i], i, c);
            if (visited.count(c)) continue;
            visited.insert(c);
            vector<int> cc;
            cc.push_back(c);
            int it = c;
            while (!visited.count(get_next(it))) {
                it = get_next(it);
                // dbg(it);
                cc.push_back(it);
                visited.insert(it);
                debugging++;
                assert(debugging < 200000);
            }
            reverse(cc.begin(), cc.end());
            int first_one = get_next(it);
            // dbg(first_one, cc.back());
            while (!cc.empty() and cc.back() != first_one) cc.pop_back();
            if (cc.empty()) continue;
            reverse(cc.begin(), cc.end());
            int bb = 0;
            for (int x : cc) bb |= (1<< MAPPA[x]);
            // dbg(bb, SZ(cc), __builtin_popcount(bb));
            if (__builtin_popcount(bb) != SZ(cc)) continue;
            cycles[bb].push_back(cc);
            is_cycle[bb] = true;
            // dbg(bb);
        }
    }
    din[0] = true;
    for (int bb = 1; bb < (1<<K); bb++) {
        if (is_cycle[bb]) {
            din[bb] = true;
            continue;
        }
        // go through subsets
        for (int cc = bb; cc > 0; cc = (cc-1)&bb) {
            if (is_cycle[bb^cc] and din[cc]) din[bb] = true;
        }
    }
    if (din[(1<<K)-1] == false) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    int bb = (1<<K)-1;
    vector<pair<LL,int>> ans(K);
    int deb2 = 0;
    while (bb != 0) {
        deb2++;
        assert(deb2 < 20);
        for (int cc = 0; cc < (1<<K); cc++) {
            if ((cc&bb) != cc) continue;
            if (!is_cycle[cc] or !din[bb^cc]) continue;
            vector<int> cyc = cycles[cc][0];
            int L = SZ(cyc);
            for (int i = 0; i < L; i++) {
                ans[MAPPA[cyc[(i+1)%L]]] = {cyc[(i+1)%L], MAPPA[cyc[i]]};
            }   
            bb ^= cc;
            break;
        }
    }
    for (auto pp : ans) {
        cout << pp.first << " " << pp.second+1 << "\n";
    }
}