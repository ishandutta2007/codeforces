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

void check(string A, string B, vector<int> moves) {
    for (int x: moves) {
        for (int i = 0; i <= x; i++) A[i] = (A[i]=='0')?'1':'0';
        for (int i = 0; i < x-i; i++) swap(A[i], A[x-i]);
    }
    // dbg(moves);
    // dbg(A, B);
    assert(A == B);
}

void solve() {
    int N;
    cin >> N;
    string A;
    string B;
    cin >> A >> B;
    int cnt = 0;
    int sum = 0;
    auto get_val = [&](int id) {
        if (cnt%2 == 0) return A[sum + id];
        return (A[sum-id] == '0')?'1':'0';
    };
    vector<int> moves;
    for (int i = N-1; i >= 0; i--) {
        if (get_val(i) == B[i]) continue;
        if (B[i] != get_val(0)) moves.push_back(i);
        else {
            moves.push_back(0);
            moves.push_back(i);
        }

        cnt++;
        if (cnt%2) sum = sum+i;
        else sum = sum-i;
    }
    cout << moves.size() << " ";
    for (int x: moves) cout << x+1 << " ";
    cout << "\n";

    // cout.flush();
    // check(A, B, moves);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}