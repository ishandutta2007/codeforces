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

const int MAXN = 1e7 + 10;

LL N;
int cntppp[MAXN];
int ppp[MAXN];
int phi[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;
    if (N <= 3) {
        cout << 0 << "\n";
        return 0;
    }
    for (int p = 2; p <= N; p++) {
        if (ppp[p]) continue;
        for (int i = p; i <= N; i+=p) {
            if (ppp[i] == 0) {
                cntppp[p]++;
                ppp[i] = p;
            }
        }
    }
    phi[1] = 1;
    for (int k = 2; k <= N; k++) {
        int p = ppp[k];
        phi[k] = p-1;
        int it = k / p;
        while (it % p == 0) it /= p, phi[k] *= p;
        phi[k] *= phi[it];
    }
    // dbg_array(ppp, N+1);
    LL big_primes = 0;
    for (int i = 2; i <= N; i++) {
        if (ppp[i] == i and i*2 > N) big_primes++;
    }
    LL appb = 0;
    for (LL i = 2; i <= N; i++) {
        if (ppp[i] != i) continue;
        for (LL j = i; i*j <= N; j++) {
            if (ppp[j] != j) continue;
            if (i != j) appb += (LL)cntppp[i]*(LL)cntppp[j];
            else appb += ((LL)cntppp[i] * ((LL)cntppp[i]-1ll) ) / 2ll;
        }
    }
    LL asimb = 0;
    for (LL i = 2; i <= N; i++) {
        asimb += i-1-phi[i];
    }
    // dbg_var(asimb);
    // dbg_var(appb);
    // dbg_var(big_primes);
    LL all_pairs = ((N-big_primes-1) * (N-big_primes-2ll)) / 2ll;
    cout << 3ll * all_pairs - appb - asimb << "\n";
}