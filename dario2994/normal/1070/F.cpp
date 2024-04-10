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

LL improve(vector<LL> a, vector<LL> b, int K) {
    // dbg_var(a);
    // dbg_var(b);
    // dbg_var(K);
    LL res = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int j = min((int)b.size()-1, K-i);
        if (0 <= j and i <= j+K) res = max(res, a[i] + b[j]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<LL> a(1, 0), b(1, 0), c(1, 0), d(1, 0);
    for (int i = 0; i < N; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "00") a.push_back(x);
        if (s == "01") b.push_back(x);
        if (s == "10") c.push_back(x);
        if (s == "11") d.push_back(x);
    }
    sort(a.begin()+1, a.end(), greater<LL>());
    sort(b.begin()+1, b.end(), greater<LL>());
    sort(c.begin()+1, c.end(), greater<LL>());
    sort(d.begin()+1, d.end(), greater<LL>());
    for (int i = 1; i < (int)a.size(); i++) a[i] += a[i-1];
    for (int i = 1; i < (int)b.size(); i++) b[i] += b[i-1];
    for (int i = 1; i < (int)c.size(); i++) c[i] += c[i-1];
    for (int i = 1; i < (int)d.size(); i++) d[i] += d[i-1];
    // dbg_var(a);
    // dbg_var(b);
    // dbg_var(c);
    // dbg_var(d);

    LL res = 0;
    res += d.back();
    int l = min(b.size(), c.size());
    res += b[l-1] + c[l-1];
    if ((int)b.size() > l) {
        vector<LL> vec(0);
        for (int i = l-1; i < (int)b.size(); i++) vec.push_back(b[i]-b[l-1]);
        res += improve(a, vec, d.size()-1);
    } else {
        vector<LL> vec(0);
        for (int i = l-1; i < (int)c.size(); i++) vec.push_back(c[i]-c[l-1]);
        res += improve(a, vec, d.size()-1);
    }
    cout << res << "\n";
}