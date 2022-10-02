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
    string S;
    cin >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = (S[i] == 'L')?0:1;
    int state[2][2];
    int new_state[2][2];
    int res = 1e8;
    for (int x = 0; x <= 1; x++) for (int y = 0; y <= 1; y++) {
        for (int a = 0; a <= 1; a++) for (int b = 0; b <= 1; b++) state[a][b] = 1e8;
        state[x][y] = (x != A[0]);
        state[x][y] += (y != A[1]);
        // for (int aa = 0; aa <= 1; aa++) for (int bb = 0; bb <= 1; bb++) cout << state[aa][bb] << " ";
        // cout << endl;
        for (int i = 2; i < N; i++) {
            for (int a = 0; a <= 1; a++) for (int b = 0; b <= 1; b++) {
                new_state[a][b] = (b != A[i]);
                if (a == b) new_state[a][b] += state[!a][a];
                else new_state[a][b] += min(state[a][a], state[!a][a]);
            }
            // bool ccc = 1 != S[i];
            // dbg(i, state[1][0], ccc);
            for (int a = 0; a <= 1; a++) for (int b = 0; b <= 1; b++) state[a][b] = new_state[a][b];
            // dbg(i, state[0][1]);
            // for (int aa = 0; aa <= 1; aa++) for (int bb = 0; bb <= 1; bb++) cout << state[aa][bb] << " ";
            // cout << endl;
        }
        int ris = 1e8;
        for (int a = 0; a <= 1; a++) for (int b = 0; b <= 1; b++) {
            if (a == b and b == x) continue;
            if (b == x and x == y) continue;
            ris = min(ris, state[a][b]);
        }
        res = min(res, ris);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}