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

#define INF 1<<30
#define eps 1e-9

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

// Computes the inverse of n modulo m.
// Precondition: n, m > 0 and gcd(n, m) == 1.
ULL Inverse(ULL n, ULL m) {
	if (n == 1) return 1;
	ULL y = Inverse(m % n, n);
	return m - ((m * y - 1) / n) % m;
}

const LL mod = 1e9 + 7;
const int MAXN = 200100;
LL A[MAXN];

LL IterateEven(LL arr[], int K) {
    LL res = arr[0];
    LL binom = 1;
    for (int i = 1; i <= K; i++) {
        LL pr = K+1-i;
        pr *= (LL)Inverse(i, mod);
        pr %= mod;
        binom *= pr;
        binom %= mod;

        res += binom * arr[2*i];
        res %= mod;
    }
    return res;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    if (N % 2) {
        for (int i = 0; i < N-1; i++) {
            if (i % 2) A[i] = (A[i] - A[i+1]) % mod;
            else A[i] = (A[i] + A[i+1]) % mod; 
        }
        N--;
    }

    LL ris1 = IterateEven(A, (N-2)/2);
    LL ris2 = IterateEven(A+1, (N-2)/2);

    LL res;
    if (N % 4) {
        res = ris1 + ris2;
    } else {
        res = ris1 - ris2;
    }

    res %= mod;
    cout << (res + mod) % mod << "\n";
    
}