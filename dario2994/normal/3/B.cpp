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

const int MAXN = 100100;
int cap[MAXN];
vector<int> t1;
vector<int> t2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    int V;
    cin >> N >> V;
    int ans2 = 0;
    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t >> cap[i];
        if (t == 1) t1.push_back(i);
        else {
            t2.push_back(i);
            ans2 += cap[i];
        }
    }
    sort(t1.begin(), t1.end(), [&](int x, int y) { return cap[x] > cap[y]; });
    sort(t2.begin(), t2.end(), [&](int x, int y) { return cap[x] > cap[y]; });
    int it = t2.size();
    int ans1 = 0;
    int res = 0;
    int best_i = 0, best_it = 0;
    for (int i = 0; i <= SZ(t1); i++) {
        if (i > V) break;
        while (i + 2*it > V) {
            it--;
            ans2 -= cap[t2[it]];
        }
        if (res < ans1 + ans2) {
            res = ans1 + ans2;
            best_i = i, best_it = it;
        }
        if (i < SZ(t1)) ans1 += cap[t1[i]];
    }
    cout << res << "\n";
    // cout << best_i + best_it << "\n";
    vector<int> ans;
    for (int i = 0; i < best_i; i++) ans.push_back(t1[i]);
    for (int i = 0; i < best_it; i++) ans.push_back(t2[i]);
    sort(ans.begin(), ans.end());
    for (int x: ans) cout << x << " ";
    cout << "\n";
}