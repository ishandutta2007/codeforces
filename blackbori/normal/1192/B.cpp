#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
typedef priority_queue <ll> pql;

struct node{
	ll v, l, r, s;
	
	node() : v(0), l(0), r(0), s(0) {}	
	node(ll v, ll d, ll c) : v(v), l(d + c), r(d), s(c) {}
	
	node operator + (node n)
	{
		node ret;
		
		ret.s = s + n.s;
		ret.l = max(l, s + n.l);
		ret.r = max(n.r, n.s + r);
		ret.v = max(max(v, n.v), r + n.l);
		
		return ret;
	}
};

struct segtree{
	node T[303030];
	ll sz = 1 << 17;
	
	void update(ll p, ll v, ll d, ll c)
	{
		p += sz; T[p] = node(v, d, c);
		
		for(p>>=1; p; p>>=1){
			T[p] = T[p << 1] + T[p << 1 | 1];
		}
	}
	
	node getval(ll l, ll r)
	{
		node vl, vr;
		bool fl = 0, fr = 0;
		
		l += sz; r += sz;
		
		for(; l<=r; ){
			if(l & 1){
				if(fl) vl = vl + T[l];
				else vl = T[l], fl = 1;
			}
			if(~r & 1){
				if(fr) vr = T[r] + vr;
				else vr = T[r], fr = 1;
			}
			l = l + 1 >> 1;
			r = r - 1 >> 1;
		}
		
		if(fl && fr) return vl + vr;
		else if(fl) return vl;
		else if(fr) return vr;
		else 1 / 0;
	}
};

segtree T;
vector <ll> V[101010];
pql PV[101010], QV[101010], PL[101010], QL[101010];
ll P[101010], C[101010], N[101010];
ll A[101010], B[101010], E[101010], _C[101010], Z[101010];
ll H[101010], G[101010], S[101010];
vector <ll> X;
ll n, q, w, g, cnt, ans;

void dfs1(ll p, ll r)
{
	Z[p] = 1;
	
	for(ll &t: V[p]){
		if(t != r){
			dfs1(t, p);
			Z[p] += Z[t]; P[t] = p;
		}
	}
}

void dfs2(ll p, ll r, ll c)
{
	ll m = -1;
	
	N[p] = ++cnt;
	X.push_back(p);
	
	for(ll &t: V[p]){
		if(t == r) continue;
		if(m == -1 || Z[t] > Z[m]){
			m = t;
		}
	}
	
	if(m != -1){
		G[m] = c; S[c] ++;
		dfs2(m, p, c);
	}
	
	for(ll &t: V[p]){
		if(t != r && t != m){
			H[++g] = t; G[t] = g; S[g] ++;
			dfs2(t, p, g);
			
			PV[p].push(0); PL[p].push(0);
		}
	}
}

void sync(pql &P, pql &Q) { for(; !P.empty() && !Q.empty() && P.top() == Q.top(); P.pop(), Q.pop()); }

pll nodeval(ll p)
{
	ll v, v1, v2;
	
	sync(PL[p], QL[p]);
	if(PL[p].empty()) v1 = -1;
	else v1 = PL[p].top(), PL[p].pop();
	
	sync(PL[p], QL[p]);
	if(PL[p].empty()) v2 = 0;
	else v2 = PL[p].top();
	
	if(v1 != -1) PL[p].push(v1);
	
	sync(PV[p], QV[p]);
	if(PV[p].empty()) v = 0;
	else v = PV[p].top();
	
	if(v1 == -1) v1 = 0;
	
	v = max(v, v1 + v2);
	
	return pll(v, v1);
}

void query(ll p)
{
	if(!p) return;
	
	node _n;
	ll h, v, d;
	
	h = H[G[p]];
	
	_n = T.getval(N[h], N[h] + S[G[p]] - 1);
	v = _n.v; d = _n.l;
	QV[P[h]].push(v); QL[P[h]].push(d);
	
	tie(v, d) = nodeval(p); v = max(v, d + C[p]);
	T.update(N[p], v, d, C[p]);
	
	_n = T.getval(N[h], N[h] + S[G[p]] - 1);
	v = _n.v; d = _n.l;
	PV[P[h]].push(v); PL[P[h]].push(d);
	
	query(P[h]);
}

ll getans() { return nodeval(0).first; }

int main()
{
	ll i, c;
	
	scanf("%lld%lld%lld", &n, &q, &w);
	
	for(i=1; i<n; i++){
		scanf("%lld%lld%lld", A + i, B + i, _C + i);
		V[A[i]].push_back(B[i]);
		V[B[i]].push_back(A[i]);
	}
	
	dfs1(1, 0);
	H[++g] = 1; G[1] = g; S[g] ++;
	dfs2(1, 0, g);
	PV[0].push(0); PL[0].push(0);
	
	reverse(X.begin(), X.end());
	
	for(i=1; i<n; i++){
		if(P[A[i]] != B[i]) swap(A[i], B[i]);
		E[A[i]] = i;
	}
	
	for(ll &t: X){
		C[t] = _C[E[t]];
		query(t);
	}
	
	for(i=1; i<=n; i++){
		ll v, d;
		tie(v, d) = nodeval(i);
	}
	
	for(; q--; ){
		scanf("%lld%lld", &i, &c);
		i = A[(i + ans) % (n - 1) + 1];
		c = (c + ans) % w;
		C[i] = c; query(i);
		ans = getans();
		printf("%lld\n", ans);
	}
		
	return 0;
}