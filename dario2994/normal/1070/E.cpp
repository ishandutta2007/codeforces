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

int compute(int N, const vector<LL>& p, LL mod, LL t, LL d) {
    int ris = 0;
    vector<LL> vec;
    for (int i = 0; i < N; i++) if (p[i] <= d) vec.push_back(p[i]);
    LL total = 0;
    LL curr = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        if (i % mod == 0 and i > 0) {
            total += curr;
            curr = 0;
        }
        total += vec[i];
        curr += vec[i];
        if (total <= t) ris++;
    }
    return ris;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int Test;
    cin >> Test;
    for (int tt = 0; tt < Test; tt++) {
        int N, mod;
        LL t;
        cin >> N >> mod >> t;
        vector<LL> p(N);
        for(int i = 0; i < N; i++) cin >> p[i];
        LL l = 1, r = t;
        while (l != r) {
            LL m = (l+r)/2 + 1;
            vector<LL> vec;
            for (int i = 0; i < N; i++) if (p[i] <= m) vec.push_back(p[i]);
            LL total = 0;
            LL curr = 0;
            for (int i = 0; i < (int)vec.size(); i++) {
                if (i % mod == 0 and i > 0) {
                    total += curr;
                    curr = 0;
                }
                total += vec[i];
                curr += vec[i];
            }
            if (total <= t) l = m;
            else r = m-1;
        }
        int ris1 = compute(N, p, mod, t, l);
        int ris2 = compute(N, p, mod, t, l+1);
        if (ris2 > ris1) {
            cout  << ris2 << " " << l+1 << "\n";
        } else {
            cout << ris1 << " " << l << "\n";
        }
        // int res = 0;
        // for (int i = 0; i < N; i++) if (p[i] <= l) res++;
        // cout << res << " " << l << "\n";

    }
}