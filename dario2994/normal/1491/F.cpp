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
    // #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

int _n;
vector<int> signs;

int query_pair(int a, int b) {
    assert(a != b and 1 <= a and a <= _n and 1 <= b and b <= _n);
    return signs[a] * signs[b];
}

int cf_query_pair(int a, int b) {
    cout << "? 1 1\n";
    cout << a << "\n";
    cout << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

int query_pref(int a, int b) {
    assert(1 <= a and a < b and b <= _n);
    int sum = 0;
    for (int i = 1; i <= a; i++) sum += signs[i];
    return sum * signs[b];
}

int cf_query_pref(int a, int b) {
    cout << "? " << a << " 1\n";
    for (int i = 1; i <= a; i++) cout << i << " ";
    cout << "\n";
    cout << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void print_answer(vector<int> ans) {
    sort(ans.begin(), ans.end());
    vector<int> expected_answer;
    for (int i = 1; i <= _n; i++) if (signs[i] == 0) expected_answer.push_back(i);
    assert(ans == expected_answer); 
}

void cf_print_answer(vector<int> ans) {
    cout << "! " << ans.size() << " ";
    for (int x: ans) cout << x << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    // n = _n;
    vector<int> ans;
    for (int k = 1; k < n; k++) {
        if (cf_query_pref(k, k+1)) {
            // dbg(signs, k);
            for (int h = k+2; h <= n; h++) if (!cf_query_pair(k+1, h)) ans.push_back(h);
            int l = 1;
            int r = k;
            while (l != r) {
                int m = (l+r)/2;
                if (cf_query_pref(m, k+1)) r = m;
                else l = m+1;
            }
            // dbg(ans, l);
            for (int i = 1; i <= k; i++) if (i != l) ans.push_back(i);
            break;
        }
    }
    cf_print_answer(ans);
}

void generate() {
    _n = 10;
    signs.resize(_n+1);
    int cnt = 0;
    for (int i = 1; i <= _n; i++) {
        signs[i] = (rand() % 100) == 0;
        if (rand()%2) signs[i] = -signs[i];
        cnt += signs[i] != 0;
    }
    if (cnt <= 2) generate();
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        // generate();
        solve();
    }
}