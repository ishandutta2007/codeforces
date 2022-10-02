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

void solve() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<vector<int>> suffS(26, vector<int>(N+1, 0)), suffT(26, vector<int>(N+1, 0));
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            suffS[j][i] = suffS[j][i+1];
            suffT[j][i] = suffT[j][i+1];
        }
        suffS[S[i]-'a'][i]++;
        suffT[T[i]-'a'][i]++;
    }

    for (int j = 0; j < 26; j++) {
        if (suffS[j][0] != suffT[j][0]) {
            cout << -1 << "\n";
            return;
        }
    }
    
    vector<vector<int>> last_occS(26, vector<int>(N+1, -1)), last_occT(26, vector<int>(N+1, -1));
    last_occS[S[0]-'a'][0] = 0;
    last_occT[T[0]-'a'][0] = 0;
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            last_occS[j][i] = last_occS[j][i-1];
            last_occT[j][i] = last_occT[j][i-1];
        }
        last_occS[S[i]-'a'][i] = i;
        last_occT[T[i]-'a'][i] = i;
    }
    vector<vector<int>> din(N+1, vector<int>(N+1, 1e6));
    for (int i = 0; i <= N; i++) din[i][0] = 0;
    for (int j = 0; j < N; j++) {
        din[0][j] = 0;
        for (int i = 0; i < N; i++) {
            if (suffS[T[j]-'a'][i+1] >= suffT[T[j]-'a'][j]) din[i+1][j+1] = min(din[i+1][j+1], din[i+1][j]);
            int k = last_occS[T[j]-'a'][i];
            if (k != -1) din[i+1][j+1] = min(din[i+1][j+1], din[k][j] + i-k);
        }
    }
    cout << din[N][N] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}