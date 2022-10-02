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

const int MAXN = 105000; 

int AS[MAXN], BS[MAXN];
int AT[MAXN], BT[MAXN];

bool Evaluate(int s, int as, int bs, int t, int at, int bt) {
    if (at <= as and bs <= bt and bs % 2 == bt % 2) {
        if (bs == bt) {
            if (at % 3 != as % 3) return false;
        }
        if (s == as) {
            if (t == at and s == t) return true;
            if (at == as) return false;
        }
        return true;
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    string S, T;
    cin >> S;
    cin >> T;
    for (int i = 0; i < (int)S.size(); i++) {
        BS[i+1] = BS[i] + (S[i] != 'A');
        AS[i+1] = (S[i] == 'A') ? (AS[i]+1) : 0;
    }
    for (int i = 0; i < (int)T.size(); i++) {
        BT[i+1] = BT[i] + (T[i] != 'A');
        AT[i+1] = (T[i] == 'A') ? (AT[i]+1) : 0;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int ls, rs, lt, rt;
        cin >> ls >> rs >> lt >> rt;
        ls--, lt--;
        int s = rs-ls;
        int t = rt-lt;
        cout << (Evaluate(s, min(AS[rs], s), BS[rs]-BS[ls], t, min(AT[rt], t), BT[rt]-BT[lt]) ? 1 : 0);
    }
}