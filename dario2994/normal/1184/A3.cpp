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

LL modpow(LL a, LL e, LL p) {
    if (e == 0) return 1;
    if (e % 2 == 0) return modpow(a*a % p, e/2, p);
    return modpow(a*a % p, e/2, p) * a % p;
}

// Precomputes the vectors rev and roots as required by the function fft.
// See the description of the said function for further details.
const int Z = 1<<17;
int rev[Z];
LL roots[Z];
void PreRev() {
    assert(Z > 0 and !(Z&(Z-1)));
    rev[0] = 0;
    for (int i = 1; i < Z; i++) rev[i] = (rev[i>>1]>>1) ^ ((i&1)?(Z>>1):0);
}

void PreRoots(LL p, LL unit_root) {
    for (int k = 1; k < Z; k<<=1) {
        LL w = modpow(unit_root, Z/(2*k), p);
        roots[k] = 1;
        for (int i = 1; i < k; i++) {
            roots[k+i] = roots[k+i-1] * w % p;
        }
    }
}

void FFT(vector<LL>& a, LL p) {
    // int N = a.size();
    // assert(N > 0 and !(N&(N-1)));

    for (int i = 0; i < Z; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < Z; k<<=1) {
        for (int i = 0; i < Z; i+=2*k) {
            for (int j = 0; j < k; j++) {
                LL x = a[i+j], y = a[i+k+j] * roots[k+j] % p;
                a[i+j] = x + y;
                a[i+k+j] = x - y;
            }
        }
    }
}


vector<LL> RecursiveFFT(const vector<LL>& seq, LL unit_root, LL p) {
    int N = seq.size();
    if (N == 1) return {seq[0] % p};
    vector<LL> even_seq(N/2), odd_seq(N/2);
    for (int i = 0; i < N/2; i++) {
        even_seq[i] = seq[2*i];
        odd_seq[i] = seq[2*i+1];
    }
    const auto& even_dft = RecursiveFFT(even_seq, unit_root * unit_root % p, p);
    const auto& odd_dft = RecursiveFFT(odd_seq, unit_root * unit_root % p, p);
    
    vector<LL> dft(N);
    LL current_root = 1;
    for (int i = 0; i < N; i++) {
        dft[i] = (even_dft[i % (N/2)] + current_root * odd_dft[i % (N/2)]) % p;
        current_root = current_root * unit_root % p;
    }
    return dft;
}

LL slow_find_root(const vector<LL>& Q, int N, LL p) {
    for (LL z = 2; z <= p-2; z++) {
        LL res = 0;
        for (int i = N-1; i >= 0; i--) {
            res = (res * z + Q[i]) % p;
        }
        if (res % p == 0) return z;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M;
    cin >> N >> M;
    PreRev();
    // cout << Z << endl;
    vector<LL> pol(Z, 0);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        pol[i] += c-'a';
    }
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        pol[i] -= c-'a';
    }
    // dbg(pol);
    for (LL p = Z+1; ; p += Z) {
        bool is_prime = true;
        for (int d = 2; d*d <= p; d++) if (p%d == 0) {
            is_prime = false;
            break;
        }
        if (!is_prime) continue;
        // dbg(p);
        LL primitive;
        LL unit_root;
        for (LL a = 2;; a++) {
            if (modpow(a, (p-1)/2, p) != 1) {
                primitive = a;
                unit_root = modpow(a, (p-1)/Z, p);
                break;
            }
        }
        
        // cout << p << " " << unit_root << " " << modpow(unit_root, Z, p) << " " << modpow(unit_root, Z/2, p) << endl;
        LL pot = 1;
        // cout << slow_find_root(pol, N, p) << endl;
        for (int j = 0; j < (p-1)/Z; j++) {
            vector<LL> Q = pol;
            LL pot2 = 1;
            for (int i = 0; i < N; i++) Q[i] = Q[i] * pot2 % p, pot2 = pot*pot2 % p;
            PreRoots(p, unit_root);
            // Q = RecursiveFFT(Q, unit_root, p);
            FFT(Q, p);
            for (int i = 0; i < Z; i++) if (Q[i] % p == 0) {
                if (j == 0 and (i == 0 or i == (Z/2))) continue;
                LL r = pot * modpow(unit_root, i, p) % p;
                cout << p << " " << r << "\n";
                // dbg(j);
                // LL res = 0;
                // LL ppp = 1;
                // for (int i = 0; i < N; i++) res += pol[i] * ppp % p, ppp = ppp * r % p;
                // res %= p;
                // assert(res == 0);
                return 0;
            }
            pot = pot * primitive % p;
        }
    } 
    
}