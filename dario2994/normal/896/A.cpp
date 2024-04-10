#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 100100; 


const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string pref = "What are you doing while sending \"";
const string mid = "\"? Are you busy? Will you send \"";
const string suff = "\"?";

const LL INF = 1e18+5;
LL len[MAXN];

char solve(LL n, LL k) {
    // if (n % 1000 == 0) cout << n << endl;
    if (k >= len[n]) return '.';
    if (n == 0) return f0[k];
    if (k < (int)pref.size()) return pref[k];
    k -= pref.size();
    if (k < len[n-1]) return solve(n-1, k);
    k -= len[n-1];
    if (k < (int)mid.size()) return mid[k];
    k -= (int)mid.size();
    if (k < len[n-1]) return solve(n-1, k);
    k -= len[n-1];
    return suff[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    len[0] = f0.size();
    for (int i = 0; i < MAXN-1; i++) {
        if (len[i] == INF) len[i+1] = INF;
        else len[i+1] = min(INF, LL(2*len[i] + pref.size() + mid.size() + suff.size()));
    }

    int Q;
    // cout << "BEFORE" << endl;
    cin >> Q;
    // cout << "AFTER" << endl;
    for (int q = 0; q < Q; q++) {
        LL n, k;
        cin >> n >> k;
        k--;
        cout << solve(n, k);
    }
    cout << "\n";
}