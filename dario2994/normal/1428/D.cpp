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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> lows, highs;
    vector<bool> used(N, false);
    vector<int> height(N);
    int row = N-1;
    vector<pair<int,int>> ans;
    for (int i = N-1; i >= 0; i--) {
        while (!highs.empty() and used[highs.back()]) highs.pop_back();
        while (!lows.empty() and used[lows.back()]) lows.pop_back();
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            ans.push_back({row, i});
            lows.push_back(i);
            height[i] = row;
            row--;
        } else if (a[i] == 2) {
            if (lows.empty()) {
                cout << -1 << "\n";
                return 0;
            }
            int it = lows.back();
            used[it] = true;
            ans.push_back({height[it], i});
            highs.push_back(i);
        } else if (a[i] == 3) {
            if (highs.empty() and lows.empty()) {
                cout << -1 << "\n";
                return 0;
            }
            int it = -1;
            if (!highs.empty()) it = highs.back();
            else it = lows.back();
            used[it] = true;
            ans.push_back({row, it});
            ans.push_back({row, i});
            row--;
            highs.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto pp: ans) {
        cout << pp.first+1 << " " << pp.second+1 << "\n";
    }

    // vector<string> vec(N, string(N, '.'));
    // for (auto pp: ans) {
        // assert(0 <= pp.first and pp.first < N);
        // assert(0 <= pp.second and pp.second < N);
        // vec[pp.first][pp.second] = 'X';
    // }
    // cout << endl;
    // for (int i = 0; i < N; i++) cout << vec[i] << "\n";
}