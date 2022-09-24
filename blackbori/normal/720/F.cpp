#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

struct group{
	ll x, c, l, r; group() {}
	group(ll x, ll c, ll l, ll r) :
		x(x), c(c), l(l), r(r) {}
};

struct fenwick{
	ll C[131313], M[131313], V[131313];
	ll sz = 1 << 17;

	void init() {
		fill(C, C + 131313, 0); fill(M, M + 131313, 1e9), fill(V, V + 131313, 0); }
	void add(ll i, ll x, ll v) {
		for(; i <= sz; i += i & -i) C[i] ++, M[i] = min(M[i], x), V[i] += v; }
	ll getc(ll i) { return i? getc(i - (i & -i)) + C[i] : 0; }
	ll getm(ll i) { return i? min(getm(i - (i & -i)), M[i]) : 1e9; }
	ll getv(ll i) { return i? getv(i - (i & -i)) + V[i] : 0; }

	pll findn(ll i)
	{
		ll j, s = 0, c;

		if(i == 0) j = 1 << 17;
		else for(; i < sz; i += j, s += C[i]){
			for(j = i & -i; i & j; j <<= 1){
				s -= C[i]; i -= j;
			}
			if(s + C[i + j] > 0) break;
		}

		if(i >= sz) return pll(i, 0);

		c = s + C[i + j];
		for(j >>= 1; j; j >>= 1){
			if(s + C[i + j] <= 0){
				i += j; s += C[i];
			}
			else c = min(c, s + C[i + j]);
		}

		return pll(i + 1, c);
	}
} F;

struct setpair{
	multiset <ll> S1, S2;
	ll s;

	void insert(ll v)
	{
		if(!S1.empty() && *S1.begin() <= v){
			S1.insert(v); s += v; 
		}
		else S2.insert(v);
	}

	void erase(ll v)
	{
		auto it = S1.lower_bound(v);
		if(it != S1.end() && *it == v){
			S1.erase(it); s -= v;
		}
		else{
			it = S2.lower_bound(v);
			S2.erase(it);
		}
	}

	ll topk(ll k)
	{
		if(S1.size() + S2.size() < k) return -1e18;
		for(; S1.size() < k; ){
			auto it = prev(S2.end());
			S1.insert(*it); s += *it;
			S2.erase(it);
		}
		for(; S1.size() > k; ){
			auto it = S1.begin();
			S2.insert(*it); s -= *it;
			S1.erase(it);
		}
		return s;
	}
} P;

struct node{
	ll mn, mx, vn, vx; node() {}
	node(ll x) : mn(x), mx(x), vn(0), vx(0) {}
	node operator + (node &n)
	{
		node r;
		r.mn = min(mn, n.mn); r.mx = max(mx, n.mx);
		r.vn = min(min(vn, n.vn), n.mn - mx);
		r.vx = max(max(vx, n.vx), n.mx - mn);
		return r;
	}
};

struct segtree{
	node T[303030];
	ll sz = 1 << 17;

	void init(ll n, ll *S)
	{
		ll i;
		for(i = 0; i <= n; i ++) T[sz + i] = node(S[i]);
		for(i = sz - 1; i; i --) T[i] = T[i << 1] + T[i << 1 | 1];
	}

	ll getval(ll l, ll r, ll t)
	{
		node lv, rv;
		ll lf = 0, rf = 0;

		l += sz; r += sz;
		for(; l <= r; ){
			if(l & 1){
				if(!lf) lv = T[l];
				else lv = lv + T[l];
				lf = 1; l ++;
			}
			if(~r & 1){
				if(!rf) rv = T[r];
				else rv = T[r] + rv;
				rf = 1; r --;
			}
			l >>= 1; r >>= 1;
		}
		if(!lf) lv = rv;
		if(rf) lv = lv + rv;

		if(t == 0) return lv.mn;
		else if(t == 1) return lv.mx;
		else return max(lv.vx, -lv.vn);
	}
} T;

vector <ll> X;
vector <group> K;
set <ll> C;
ll A[101010], S[101010], D[101010], V[101010];
ll n, k, ans, z;

ll getcoor(ll x) {
	return upper_bound(X.begin(), X.end(), x) - X.begin(); }

pll calc(ll x)
{
	ll i, t, c, s = 0, v = 0;

	F.init(); F.add(S[0] + 1, 0, X[S[0]]);
	for(i = 1; i <= n; i ++){
		t = getcoor(X[S[i]] - x);
		c = F.getc(t); s += c;
		v += X[S[i]] * c - F.getv(t);
		F.add(S[i] + 1, i, X[S[i]]);
	}

	return pll(s, v);
}

ll find(ll t)
{
	ll s, e, m;
	for(s = -5e9, e = 5e9; s <= e; ){
		m = s + e >> 1;
		if(calc(m).first >= t) s = m + 1;
		else e = m - 1;
	}
	return s - 1;
}

void update(ll l, ll r, ll t)
{
	if(l == 1 && r == n) return;
	else if(l == 1){
		ll v = X[S[r]] - T.getval(l - 1, r, 0);
		z += t > 0? v : -v;
	}
	else if(r == n){
		ll v = T.getval(l - 1, r, 1) - X[S[l - 1]];
		z += t > 0? v : -v;
	}
	else{
		ll v1 = X[S[r]] - X[S[l - 1]];
		ll v2 = T.getval(l - 1, r, 2);
		if(t > 0) z += v1, P.insert(v2);
		else z -= v1, P.erase(v2);
	}
}

void erase(ll l, ll r)
{
	auto it = C.lower_bound(l);
	if(*it > r) return;
	update(*prev(it) + 1, *it - 1, -1);
	for(; *it <= r; ){
		update(*it + 1, *next(it) - 1, -1);
		z -= A[*it]; it ++;
		C.erase(prev(it));
	}
	update(*prev(it) + 1, *it - 1, 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll i, j, s, e, t, v, c;

	cin >> n >> k;

	for(i = 1; i <= n; i ++){
		cin >> A[i];
		S[i] = S[i - 1] + A[i];
		X.push_back(S[i]);
	}

	T.init(n, S);

	X.push_back(0);
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	for(i = 0; i <= n; i ++){
		S[i] = getcoor(S[i]) - 1;
	}

	s = find(k - n) + 1;
	e = find(k);

	F.init(); F.add(S[0] + 1, 0, 0);
	for(i = 1; i <= n; i ++){
		t = getcoor(X[S[i]] - s);
		v = F.getm(t);
		if(v < i) D[i] ++, D[v] --;
		for(; ; ){
			tie(t, c) = F.findn(t);
			if(t > X.size() || X[t - 1] > X[S[i]] - e) break;
			K.emplace_back(X[S[i]] - X[t - 1], c, F.getm(t) + 1, i);
		}
		F.add(S[i] + 1, i, 0);
	}

	tie(t, z) = calc(s);
	C.insert(0); C.insert(n + 1);
	for(i = n; i >= 1; i --){
		D[i] += D[i + 1];
		if(!D[i]){
			z += A[i];
			C.insert(i);
		}
	}

	for(auto it = C.begin(); next(it) != C.end(); it ++){
		update(*it + 1, *next(it) - 1, 1);
	}

	sort(K.begin(), K.end(), [&](group &a, group &b){
		return a.x > b.x;
	});

	ans = -9e18;

	for(i = n, j = 0; i >= 0; i --){
		for(; t < k - i; j ++){
			erase(K[j].l, K[j].r);
			t += K[j].c; z += K[j].c * K[j].x;
		}
		if(i > k || (!i && C.size() > 2) || C.size() < i + 2) continue;
		ans = max(ans, z - (j? (t - k + i) * K[j - 1].x : 0) + (i? P.topk(i - 1) : 0));
	}

	cout << ans << "\n";

	return 0;
}