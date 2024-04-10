#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

// Computes the inverse of n modulo m.
// Precondition: n >= 0, m > 0 and gcd(n, m) == 1.
// The returned value satisfies 0 <= x < m (Inverse(0, 1) = 0).
// ACHTUNG: It must hold max(m, n) < 2**31 to avoid integer overflow.
LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

// Fast exponentiation modulo mod. Returns x**e modulo mod.
// Assumptions: 0 <= x < mod
//              mod < 2**31.
//              0 <= e < 2**63
LL pow(LL x, LL e, LL mod) {
    LL res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

// Struct that computes x % mod faster than usual, if mod is always the same.
// It gives a x1.8 speed up over the % operator (with mod ~ 1e9 and x large).
// It is an implementation of the Barrett reduction, see
//    https://en.wikipedia.org/wiki/Barrett_reduction .
// If fast_mod is an instance of the class, then fast_mod(x) will return
// x % mod. There are no restrictions on the values of mod and x, provided
// that they fit in an unsigned long long (and mod != 0).
//
// ACHTUNG: The integer type __uint128_t must be available.
struct FastMod {
    ULL mod;
    ULL inv;
    FastMod(ULL mod) : mod(mod), inv(-1ULL / mod) {}
    ULL operator()(ULL x) {
        ULL q = (ULL)((__uint128_t(inv) * x) >> 64);
        ULL r = x - q * mod;
        return r - mod * (r >= mod);
    }
};

// Class for integers modulo mod.
// It supports all expected operations: +, -, *, /, pow, ==, < and >.
// It is as fast as it can be.
// The modulo mod shall be set through set_mod().
//
// Assumptions: mod < (1<<30).
// ACHTUNG: The integer type __uint128_t must be available.
//
// Remark: To handle larger moduli (up to 1<<62), one has to:
//          1. replace int in the definitions of mod, n.
//          2. The parameter of fast_mod must be __uint128_t, so it must be
//             changed in the definition of fast_mod and in the definition of
//             the operators * and *=.
//          3. fast_mod must be a naive modulo operation, no barrett reduction.
//          4. In Inverse, __int128_t shall be used.
struct ModularInteger {
    static int mod;
    static __uint128_t inv_mod; // Necessary for fast_mod.
    int n; // 0 <= n < mod at all times
    static void set_mod(int _mod) {
        mod = _mod;
        inv_mod = -1ULL / mod;
    }
    ModularInteger(): n(0) {}
    ModularInteger(LL _n): n(_n % mod) {
        n += (n<0)*mod;
    }
    LL get() const { return n; }
    static int fast_mod(ULL x) { // Barrett reduction.
        ULL q = (inv_mod * x) >> 64;
        int m = x - q * mod;
        m -= mod * (m >= mod);
        return m;
    }

    ModularInteger operator-() const { return n?mod-n:0; }
};
int ModularInteger::mod;
__uint128_t ModularInteger::inv_mod;

ModularInteger operator +(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n + B.n;
    C.n -= (C.n >= ModularInteger::mod)*ModularInteger::mod;
    return C;
}

void operator +=(ModularInteger& A, const ModularInteger& B) {
    A.n += B.n;
    A.n -= (A.n >= ModularInteger::mod)*ModularInteger::mod;
}

ModularInteger operator -(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n - B.n;
    C.n += (C.n < 0)*ModularInteger::mod;
    return C;
}

void operator -=(ModularInteger& A, const ModularInteger& B) {
    A.n -= B.n;
    A.n += (A.n < 0)*ModularInteger::mod;
}

ModularInteger operator *(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
    return C;
}

void operator *=(ModularInteger& A, const ModularInteger& B) {
    A.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
}

// Assumption: gcd(B, mod) = 1.
ModularInteger operator /(const ModularInteger& A, const ModularInteger& B) {
    return A * Inverse(B.n, ModularInteger::mod);
}

// Assumption: gcd(B, mod) = 1.
void operator/=(ModularInteger& A, const ModularInteger& B) {
    A *= Inverse(B.n, ModularInteger::mod);
}

ModularInteger power(ModularInteger A, ULL e) {
    ModularInteger res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res *= A;
        A *= A;
    }
    return res;
}

bool operator ==(const ModularInteger& A, const ModularInteger& B) {
    return A.n == B.n;
}
bool operator !=(const ModularInteger& A, const ModularInteger& B) {
    return A.n != B.n;
}
bool operator <(const ModularInteger& A, const ModularInteger& B) {
    return A.n < B.n;
}
bool operator >(const ModularInteger& A, const ModularInteger& B) {
    return A.n > B.n;
}
bool operator <=(const ModularInteger& A, const ModularInteger& B) {
    return A.n <= B.n;
}
bool operator >=(const ModularInteger& A, const ModularInteger& B) {
    return A.n >= B.n;
}

ostream& operator <<(ostream& out, const ModularInteger& A) {
    out << A.n;
    return out;
}

istream& operator >>(istream& in, ModularInteger& A) {
  LL a;
  in >> a;
  A = ModularInteger(a);
  return in;
}

typedef ModularInteger mint;

// Treap implementation.
// A treap is a randomly balanced binary search tree that performs all
// operations in O(log(N)).
// All operations (Insert, Remove, GetNodeFromPosition, GetNodeRange) are
// implemented without rotations and exploiting only the two core functions:
// Split (that splits the tree with respect to a given key) and Merge (that
// merges a tree with small keys with a tree with big keys).
//
// With some minor changes, the datastructure can become persistent.
// Furthermore, and this is super-important, it is possible to split also
// on a given position (and not on a given key). This can be achieved modifying
// the Split function.

#include <cstdlib>
#include <vector>
using namespace std;

// The class name is NodeObj instead of Node as the latter is reserved
// for pointers. The empty treap is identified by a nullptr.
template <typename T>
struct NodeObj {
    NodeObj(T key) :
        key(key),
        priority(rand()),
        left(nullptr),
        right(nullptr),
        size(1) {}

    T key;
    int priority;
    NodeObj* left;
    NodeObj* right;
    int sum;

    int size;

    void Propagate() {
        if (sum == 0) return;
        if (left != nullptr) {
            left->key += sum;
            left->sum += sum;
        }
        if (right != nullptr) {
            right->key += sum;
            right->sum += sum;
        }
        sum = 0;
    }
};
template <typename T>
using Node = NodeObj<T>*;

// Updates the size of a node assuming that those of the children are correct.
// If the node is enriched with further informations (i.e. the sum of all
// the descendants) those info should be updated here exactly as size is.
template <typename T>
void Update(Node<T> v) {
    if (v == nullptr) return;
    v->size = 1;
    if (v->left) v->size += v->left->size;
    if (v->right) v->size += v->right->size;
}

// The treap l will contain all elements with key less or equal than key,
// the treap r all the others.
// The original treap v is modified.
template <typename T>
void Split(Node<T> v, T key, Node<T>& l, Node<T>& r, bool equal_go_left=true) {
    if (v == nullptr) {
        l = nullptr;
        r = nullptr;
        return;
    }
    v->Propagate();
    if (v->key < key or (v->key == key and equal_go_left)) {
        l = v;
        Split(v->right, key, l->right, r, equal_go_left);
    } else {
        r = v;
        Split(v->left, key, l, r->left, equal_go_left);
    }
    Update(l), Update(r);
}

// All keys in l must be less than all keys in r.
// The treaps l, r are modified during the operation.
template <typename T>
Node<T> Merge(Node<T> l, Node<T> r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    l->Propagate();
    r->Propagate();
    if (l->priority > r->priority) {
        l->right = Merge(l->right, r);
        Update(l);
        return l;
    } else {
        r->left = Merge(l, r->left);
        Update(r);
        return r;
    }
}

template <typename T>
Node<T> Search(Node<T> v, T key) {
    if (v == nullptr) return nullptr;
    v->Propagate();
    if (v->key == key) return v;
    if (v->key > key) return Search(v->left, key);
    return Search(v->right, key);
}

// Insert the new node into the treap. If a node with the same key is already
// present in the treap, nothing is done.
template <typename T>
void Insert(Node<T>& root, T key) {
    if (Search(root, key) != nullptr) return;
    Node<T> l = nullptr;
    Node<T> r = nullptr;
    Split(root, key, l, r);
    root = Merge(Merge(l, new NodeObj<T>(key)), r);
}

// The node with the given key is removed. If such a node was not present,
// nothing is done.
template <typename T>
void Remove(Node<T>& root, T key) {
    Node<T> l = nullptr;
    Node<T> r = nullptr;
    Split(root, key, l, r, true);
    Node<T> l1 = nullptr;
    Node<T> l2 = nullptr;
    Split(l, key, l1, l2, false);
    root = Merge(l1, r);
}

template<typename T>
void Print(Node<T> root) {
    if (root == nullptr) return;
    cout << root->key << " " << root->sum << endl;
    if (root->left) {
        cout << "L: " << endl;
        Print(root->left);
    }
    if (root->right) {
        cout << "R: " << endl;
        Print(root->right);
    }
}

// Returns the node in the given position. Positions are 0-based.
// It must hold pos < v->size.
// template <typename T>
// Node<T> GetNodeFromPosition(Node<T> v, int pos) {
    // int left_sz = 0;
    // if (v->left) left_sz = v->left->size;
    // if (left_sz > pos) return GetNodeFromPosition(v->left, pos);
    // if (left_sz == pos) return v;
    // return GetNodeFromPosition(v->right, pos-left_sz-1);
// }

// Returns a Node that represents the root of the tree of all elements with
// keys in [key_left, key_right]. This does NOT break the original treap.
// This is very useful to make queries on ranges.
// It must hold key_left <= key_right.
// ACHTUNG: The left and right sons of the returned node should NOT be used.
// template <typename T>
// Node<T> GetNodeRange(Node<T> root, T key_left, T key_right) {
    // Node<T> l = nullptr;
    // Node<T> r = nullptr;
    // Split(root, key_right, l, r, true);
    // Node<T> l2 = nullptr;
    // Node<T> m = nullptr;
    // Split(l, key_left, l2, m, false);
    // Node<T> res = nullptr;
    // if (m) {
        // res = new NodeObj<T>(key_left);
        // *res = *m;
    // }
    // root = Merge(Merge(l2, m), r);
    // return res; 
// }

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 5e5;
mint fact[MAXN];

mint binom(int a, int b) {
    return fact[a] / (fact[b] * fact[a-b]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    Node<int> root = nullptr;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        // cin >> y;
        // dbg(i);

        Node<int> l, r;
        Split(root, y-1, l, r);
        Remove(l, y-1);
        // dbg(i, y, l?l->size:0, r?r->size:0);
        if (r != nullptr) {
            r->sum++;
            r->key++;
        }
        Insert(l, y);
        // cout << "l" << endl;
        // Print(l);
        // cout << "r" << endl;
        // Print(r);
        root = Merge(l, r);
        // cout << "root" << endl;
        // Print(root);
    }
    int k = (root != nullptr) ? root->size : 0;
    // dbg(k);
    cout << binom(2*n-1-k, n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    mint::set_mod(998244353);
    fact[0] = 1;
    for (int n = 1; n < MAXN; n++) fact[n] = n * fact[n-1];

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}