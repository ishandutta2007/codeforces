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

const int MAXN = 2e6+100;
const LL mod = 1e9+7;
int esp[MAXN];
int ppp[MAXN];
int from[MAXN];
bool single_use[MAXN];
int cnt[MAXN];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int p = 2; p < MAXN; p++) {
        if (ppp[p]) continue;
        ppp[p] = p;
        for (int i = 2*p; i < MAXN; i+=p) ppp[i] = p;
    }

    int N;
    cin >> N;
    vector<int> primes(N);
    for (int i = 0; i < N; i++) cin >> primes[i];
    sort(primes.begin(), primes.end());
    reverse(primes.begin(), primes.end());

    for (int i = 0; i < N; i++) {
        int p = primes[i];
        if (esp[p]) {
            int x = p-1;
            while (x != 1) {
                int e = 0;
                int q = ppp[x];
                while (x % q == 0) e++, x /= q;
                if (esp[q] < e) {
                    esp[q] = e;
                    cnt[q] = 1;
                } else if (esp[q] == e) cnt[q]++;
            }
        } else {
            single_use[i] = true;
            esp[p]++;
            cnt[p] = 1;
        }
    }

    int add1 = 0;
    for (int i = 0; i < N; i++) {
        int p = primes[i];
        if (single_use[i]) continue;
        int x = p-1;
        bool useful = false;
        while (x != 1) {
            int e = 0;
            int q = ppp[x];
            while (x % q == 0) e++, x /= q;
            if (esp[q] == e and cnt[q] == 1) useful = true;
        }
        if (!useful) add1 = 1;
    }

    LL res = 1;
    for (int p = 2; p < MAXN; p++) {
        for (int e = 0; e < esp[p]; e++) res = (res * p)%mod;
    }
    cout << (res + add1)%mod<< "\n";
}