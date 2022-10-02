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

const int MAXN = 2e5 + 100;
string S;
const int L = 500;
int pref[MAXN];
int n1[MAXN];
int sum1[MAXN];
int memo[MAXN*(L+2)];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    string S;
    cin >> S;
    int N = S.size();
    LL res = 0;
    for (int l = 1; l <= min(L, N); l++) {
        pref[0] = 0;
        // unordered_map<int,int> memo; // slowest part!
        memo[N] = 1;
        for (int i = 0; i < N; i++) {
            pref[i+1] = pref[i] + ((S[i] == '0')?(-1):(l-1));
            res += memo[N+pref[i+1]];
            memo[N+pref[i+1]]++;
        }
        for (int i = 0; i <= N; i++) memo[N+pref[i]] = 0;
    }
    
    if (L >= N) {
        cout << res << "\n";
        return 0;
    }
    // cout << "FINISHED PHASE1" << endl;

    n1[N] = N;
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == '1') n1[i] = i;
        else n1[i] = n1[i+1];
    }
    for (int i = 0; i < N; i++) {
        sum1[i+1] = sum1[i] + (S[i]=='1');
    }
    for (int i = 0; i < N; i++) {
        int j = i-1;
        int c = 0;
        while (j < N-1) {
            j = n1[j+1];
            c++;
            while (j < N and j-i+1 < c*(L+1)) {
                j = i+c*(L+1)-1;
                if (j >= N) break;
                c = sum1[j+1]-sum1[i];
            }if (j >= N) break;
            int from = j-i+1, toto = n1[j+1]-i;
            res += 1 + toto/c - (from+(c-1))/c;
        }
    }
    cout << res << "\n";
}