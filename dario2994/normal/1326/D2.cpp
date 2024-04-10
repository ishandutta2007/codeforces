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

LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

template<int Q, typename T>
struct tuple_of {
    T arr[Q]; // Very fast, but rather dangerous memory-wise. 
    T& operator[](int index) { return arr[index]; }
    const T& operator[](int index) const { return arr[index]; }
};

template<int Q, typename T>
bool operator ==(const tuple_of<Q, T>& A, const tuple_of<Q, T>& B) {
    for (int q = 0; q < Q; q++) if (A[q] != B[q]) return false;
    return true;
}

template<int Q, typename T>
bool operator <(const tuple_of<Q, T>& A, const tuple_of<Q, T>& B) {
    for (int q = 0; q < Q; q++) if (A[q] != B[q]) return A[q] < B[q];
    return false;
}


// Given a string, after a linear precomputation, returns in O(1) the rolling
// hash of a substring (both of the string itself and of the reversed string).
//
// It works fine also with vectors of nonnegative integers (instead of strings), provided that the values are smaller than the base Z.
template<int Q>
struct Hasher {
    int N;
    tuple_of<Q, vector<LL>> hh; // Rolling hashes of prefixes.
    tuple_of<Q, vector<LL>> hh_rev; // Rolling hashes of prefixes of the reversed string.
    const tuple_of<Q, LL> mod;
    tuple_of<Q, vector<LL>>& inv_powers; // Not const because it can be modified by the factory.

    Hasher(const string& S, const tuple_of<Q, LL> mod, const tuple_of<Q, LL> Z, tuple_of<Q, vector<LL>>& inv_powers):
            N(S.size()), mod(mod), inv_powers(inv_powers) {
        for (int q = 0; q < Q; q++) {
            LL mod_q = mod[q];
            LL Z_q = Z[q];
            auto& hh_q = hh[q];
            auto& hh_rev_q = hh_rev[q];
            
            hh_q.resize(N+1, 0);
            hh_rev_q.resize(N+1, 0);

            LL z_pow = 1;
            for (int i = 0; i < N; i++) {
                hh_q[i+1] = (hh_q[i] + z_pow * S[i]) % mod_q;
                hh_rev_q[i+1] = (hh_rev_q[i] + z_pow*S[N-1-i]) % mod_q;
                z_pow = z_pow * Z_q % mod_q;
            }
        }
    }

    // Returns the hash of the substring [a, b].
    // If reversed is true, the hash of the reversed substring is returned.
    // For instance, get_hash(a, b) == get_hash(a, b, true) is true if and only
    // if the substring [a, b] is palindrome.
    //
    // Assumption: 0 <= a <= b < N.
    tuple_of<Q, LL> get_hash(int a, int b, bool reversed = false) {
        tuple_of<Q, LL> res;
        for (int q = 0; q < Q; q++) {
            LL ris;
            if (!reversed) {
                ris = (hh[q][b+1] - hh[q][a])*inv_powers[q][a] % mod[q];
            }
            else {
                ris = (hh_rev[q][N-a] - hh_rev[q][N-1-b])*inv_powers[q][N-1-b] % mod[q];
            }
            res[q] = (ris >= 0)?ris:(ris+mod[q]);
        }
        return res;
    }
};

template <int Q>
struct HasherFactory {
    tuple_of<Q, vector<LL>> inv_powers;
    tuple_of<Q, LL> mod;
    tuple_of<Q, LL> Z; // bases
    HasherFactory() {
        // Sophie-Germain primes.
        // This way, we can choose a base randomly (below sqrt(p)) and be sure
        // that it has order at least (p-1)/2.
        // static const vector<LL> possible_mods = {1000000403, 1000000787, 1000001447, 1000001819, 1000002359, 1000002803, 1000003919, 1000004207, 1000004519, 1000005299, 1000007003, 1000007819, 1000009859, 1000010267, 1000010723, 1000011479, 1000011659, 1000011983, 1000012463, 1000013039, 1000013087, 1000013723, 1000014167, 1000015103, 1000015187, 1000015859, 1000016063, 1000017563};
        static const vector<LL> possible_mods = {1237, 1249, 2017, 2003, 2011, 2029, 2087};

        // Generating a strong seed (see https://codeforces.com/blog/entry/60442).
        seed_seq seq{
            (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
            (uint64_t) __builtin_ia32_rdtsc()
        };
        mt19937 gen(seq);
        set<int> used_indexes;
        for (int q = 0; q < Q; q++) {
            int mod_index = uniform_int_distribution<>(0, possible_mods.size()-1)(gen);
            if (used_indexes.insert(mod_index).second == false) {
                q--;
                continue;
            }
            mod[q] = possible_mods[mod_index];
            Z[q] = uniform_int_distribution<>(1000, 30000)(gen);
        }
        InitInvPowers();    
    }

    void InitInvPowers() {
        for (int q = 0; q < Q; q++) inv_powers[q] = {1, Inverse(Z[q], mod[q])};
    }

    Hasher<Q> GetHasher(const string& S) {
        while (inv_powers[0].size() < S.size()) {
            for (int q = 0; q < Q; q++) {
                inv_powers[q].push_back(
                    inv_powers[q].back() * inv_powers[q][1] % mod[q]);
            }
        }
        return Hasher<Q>(S, mod, Z, inv_powers);
    }
};

void solve(HasherFactory<3>& HF) {
    string S;
    cin >> S;
    int N = S.size();

    int it = 0;
    while (it < N-it-1 and S[it] == S[N-it-1]) it++;
    string T;
    for (int i = it; i < N-it; i++) T += S[i];
    string res = "";
    for (int i = 0; i < it; i++) res += S[i];
    N = T.size();

    Hasher<3> H = HF.GetHasher(T);
    
    int pos = -1;
    for (int i = 0; i < N; i++) {
        if (H.get_hash(0, i) == H.get_hash(0, i, true)) pos = i;
    }
    int pos_rev = -1;
    for (int i = 0; i < N; i++) {
        if (H.get_hash(N-1-i, N-1) == H.get_hash(N-i-1, N-1, true)) pos_rev = i;
    }
    cout << res;
    if (max(pos, pos_rev) >= 0) {
        if (pos >= pos_rev) {
            for (int i = 0; i <= pos; i++) cout << T[i];
        } else {
            for (int i = N-pos_rev-1; i < N; i++) cout << T[i];
        }
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    HasherFactory<3> HF;
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve(HF);
}