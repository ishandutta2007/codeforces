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

const int MAXN = -1;

unordered_set<int> bad[10];

void generate(int K) {
    for (int bb = 0; bb < (1<<K); bb++) {
        bool works = true;
        for (int x = 0; x < K && works; x++) {
            for (int k = 1; x+2*k < K && works; k++) {
                int a = bb&(1<<x);
                int b = bb&(1<<(x+k));
                int c = bb&(1<<(x+2*k));
                a = a ? 1 : 0;
                b = b ? 1 : 0;
                c = c ? 1 : 0;
                
                if (a == b and b == c) works = false;
            }
        }
        if (works) bad[K].insert(bb);
        // if (works) cout << bb << endl;
        // if (works) {
            // for (int i = 0; i < K; i++) cout << ((bb&(1<<i))?1:0);
            // cout << endl;
        // }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    // generate(3);
    // return 0;
    for (int l = 1; l <= 9; l++) generate(l);
    
    // generate(9);
    string S;
    cin >> S;
    int N = S.size();
    LL res = ((LL)N)*(N+1ll)/2ll;
    // cout << res << endl;
    for (int i = 0; i < N; i++) {
        int val = 0;
        for (int l = 0; i + l < N; l++) {
            // cout << i << " " << l << endl;
            if (S[i+l] == '1') val += (1<<l);
            if (bad[l+1].count(val)) res--;
            else break;
        }
    }
    cout << res << "\n";
}