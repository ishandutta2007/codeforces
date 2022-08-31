#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define MAXN (1 << 19)

ll n,m, color[MAXN], beg[MAXN], en[MAXN], cur=0;
ll t[2*MAXN], d[2*MAXN];
vi nei[MAXN];

void root(int par, int node) {
	cur++, beg[node] = cur;
	for (int i: nei[node]) if (i != par) root(node,i);
	en[node] = cur;
}

void update(int ind, int l, int r, int lo, int ri, ll val) {
	if (d[ind]) {
		t[ind] = d[ind];
		if (l != r) d[2*ind] = d[ind], d[2*ind+1] = d[ind];
		d[ind] = 0;
	}
	if (lo > r || l > ri) return;
	else if (lo <= l && r <= ri) {
		t[ind] = val;
		if (l != r) d[2*ind] = val, d[2*ind+1] = val;
	} else {
		update(2*ind,l,(l+r)/2,lo,ri,val);
		update(2*ind+1,(l+r)/2+1,r,lo,ri,val);
		t[ind] = t[2*ind] | t[2*ind+1];
	}
}

ll query(int ind, int l, int r, int lo, int ri) {
	ll ans = 0;
	if (lo > r || l > ri) return (ll)(0);
	if (d[ind]) {
		t[ind] = d[ind];
		if (l != r) d[2*ind] = d[ind], d[2*ind+1] = d[ind];
		d[ind] = 0;
	}
	if (lo <= l && r <= ri) return t[ind];
	else return query(2*ind,l,(l+r)/2,lo,ri)|query(2*ind+1,(l+r)/2+1,r,lo,ri);
}

int main() {
	scanf("%d%d",&n,&m);
	FOR(i,1,n+1) scanf("%d",&color[i]);
	F0R(i,n-1) {
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y), nei[y].pb(x);
	}
	root(0,1);
	FOR(i,1,n+1) {
		update(1,1,n,beg[i],beg[i],((ll)1<<(color[i]-1)));
	}

	F0R(i,m) {
		int v,c,t;
		scanf("%d",&t);
		if (t == 1) {
			scanf("%d%d",&v,&c);
			update(1,1,n,beg[v],en[v], ((ll)1 << (c-1)));
		} else {
			scanf("%d",&v);
			printf("%d\n",__builtin_popcountll(query(1,1,n,beg[v],en[v])));
		}
	}
	return 0;
}