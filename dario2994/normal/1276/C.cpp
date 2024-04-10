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

const int MAXN = 450000; // TODO

int lodiv[MAXN];
unordered_map<int,int> occ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int d = 1; d <= min(MAXN, 10000); d++) {
        for (int i = d*d; i < MAXN; i += d) lodiv[i] = d;
    }
    
    int N;
    cin >> N;
    priority_queue<pair<int,int>> qu;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        occ[a]++;
    }
    for (auto pp : occ) qu.push({pp.second, pp.first});
    for (int area = N; area >= 1; area--) {
        int c = qu.top().first;
        if (c <= lodiv[area]) {
            cout << area << "\n";
            int p = lodiv[area];
            int q = area/p;
            cout << p << " " << q << "\n";
            vector<int> el;
            while (!qu.empty()) {
                auto pp = qu.top();
                for (int i = 0; i < pp.first; i++) el.push_back(pp.second);
                qu.pop();
            }

            vector<vector<int>> ans(p, vector<int>(q, 0));
            int diag = 0;
            int row = 0;
            for (int x : el) {
                ans[row][(diag+row)%q] = x;
                row++;
                if (row == p) row = 0, diag++;
            }
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < q; j++) cout << ans[i][j] << " ";
                cout << "\n";
            }
            return 0;
        }
        auto pp = qu.top();
        qu.pop();
        if (pp.first > 1) qu.push({pp.first-1, pp.second});
    }
}