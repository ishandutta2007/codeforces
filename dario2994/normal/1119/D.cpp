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
    vector<ULL> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];
    if (N > 1) {
        sort(s.begin(), s.end());
        vector<ULL> d(N-1);
        for (int i = 0; i < N-1; i++) d[i] = s[i+1]-s[i];
        sort(d.begin(), d.end());

        vector<ULL> val(N);
        val[0] = 0, val[1] = ((ULL)N)*d[0];
        for (int i = 1; i <= N-2; i++) {
            val[i+1] = ((ULL)(N-i))*(d[i]-d[i-1]);
            val[i+1] += val[i];
        }
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            ULL l, r;
            cin >> l >> r;
            ULL x = r-l+1;
            int it = upper_bound(d.begin(), d.end(), x)-d.begin(); // 0... N-1
            if (it == 0) cout <<  val[it] + ((ULL)N)*x << "\n";
            else cout << val[it] + (x-d[it-1])*((ULL)(N-it)) << "\n";
        }
    } else {
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            ULL l, r;
            cin >> l >> r;
            ULL x = r-l+1;
            cout << x << "\n";
        }
    }
}