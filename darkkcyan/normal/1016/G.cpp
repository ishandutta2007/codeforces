#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

using ull = unsigned long long;
using vi = vector<ll>;
void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			auto &u = a[j], &v = a[j + step]; tie(u, v) =
				inv ? make_pair(v - u, u) : make_pair(v, u + v); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				// pii(u + v, u - v);                   // XOR /// include-line
		}
	}
	// if (inv) for (int& x : a) x /= sz(a); // XOR only /// include-line
}
vi conv(vi a, vi b) {
	FST(a, 0); FST(b, 0);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST(a, 1); return a;
}

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

const int maxn = 201010;
int n;
ll x, y;
ll a[maxn];

vector<int> get_cnt_fac(ll num, const vector<ull>& fac) {
    vector<int> cnt(sz(fac));
    rep(i, 0, sz(fac)) {
        while (num % fac[i] == 0) {
            num /= fac[i];
            ++cnt[i];
        }
    }
    return cnt;
}

ll solve() {
    if (y % x) return 0;
    auto fy = factor(y);
    sort(all(fy));
    fy.erase(unique(all(fy)), fy.end());
    auto cx = get_cnt_fac(x, fy);
    auto cy = get_cnt_fac(y, fy);
    
    vector<ll> x_mask(1 << sz(fy));
    vector<ll> y_mask(1 << sz(fy));
    
    rep(i, 0, n) {
        DB();
        clog << db(i) << endl;
        auto ci = get_cnt_fac(a[i], fy);
        if (a[i] % x == 0) {
            int mask = 0;
            rep(f, 0, sz(fy)) {
                if (ci[f] == cx[f] or cx[f] == cy[f]) mask |= 1 << f;
            }
            x_mask[mask] ++;
            clog << "x " << db(mask) << endl;
        }
        
        if (y % a[i] == 0) {
            int mask = 0;
            rep(f, 0, sz(fy)) {
                if (ci[f] == cy[f] or cx[f] == cy[f]) mask |= 1 << f;
            }
            y_mask[mask]++;
            clog << "y " << db(mask) << endl;
        }
    }
    
    clog << db(x_mask) << endl;
    clog << db(y_mask) << endl;;
    
    ll ans = 0;
    
    // rep(_, 0, 2) { 
        auto t = x_mask;
        reverse(all(t));
        rep(bit, 0, sz(fy)) {
            rep(i, 0, sz(t))
                if ((i >> bit) & 1) t[i] += t[(i ^ (1 << bit))];
        }
        clog << db(t) << endl;
        rep(i, 0, sz(t)) ans += t[i] * y_mask[i];
        
        // swap(x_mask, y_mask); 
    // } 
    //  
    // rep(i, 0, sz(x_mask)) { 
        // ans -= x_mask[i] * y_mask.rbegin()[i]; 
    // } 
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> x >> y;
    rep(i, 0, n) cin >> a[i];
    auto ans = solve();
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker