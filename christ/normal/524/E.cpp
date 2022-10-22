// Problem : E. Rooks and Rectangles
// Contest : VK Cup 2015 - Round 1
// URL : https://codeforces.com/contest/524/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN =2e5+3;
int nxt[MN], ans[MN], tree[MN];
struct Rook {
	int x,y,nxt;
	void read () {scanf ("%d %d",&x,&y);}
};
struct Q {
	int x,y,x2,y2,ind;
	void read (int i) {scanf ("%d %d %d %d",&x,&y,&x2,&y2);ind=i;}
};
int n;
void build () {
	for (int i = n; i < (n<<1); i++) tree[i] = nxt[i-n+1];
	for (int i = n-1; i; i--) tree[i] = max(tree[i<<1],tree[i<<1|1]);
} 
void update (int i, int v) {
	for (tree[i+=n-1]=v;i>1;i>>=1) {
		tree[i>>1] = max(tree[i],tree[i^1]);
	}
}
int query (int l, int r) {
	int mx = 0;
	for (l+=n-1,r+=n;l<r;l>>=1,r>>=1) {
		if (l&1) mx = max(mx,tree[l++]);
		if (r&1) mx = max(mx,tree[--r]);
	}
	return mx;
}
void solve (vector<Rook> &rooks, vector<Q> &queries) {
	memset(nxt,0x3f,sizeof nxt);
	sort(all(rooks),[](Rook &a, Rook &b){return a.y > b.y;});
	for (auto &au : rooks) {
		au.nxt = nxt[au.x];
		nxt[au.x] = au.y;
	}
	reverse(all(rooks));
	sort(all(queries),[](Q &a, Q &b){return a.y < b.y;});
	build();
	int rind = 0, sz = rooks.size();
	for (Q &q : queries) {
		while (rind<sz&&rooks[rind].y<q.y) {
			update(rooks[rind].x,rooks[rind].nxt);
			rind++;
		}
		ans[q.ind] |= query(q.x,q.x2)<=q.y2;
	}
}
int main () {
	int m,k,q;
	scanf ("%d %d %d %d",&n,&m,&k,&q);
	vector<Rook> rooks(k);
	for (auto &au : rooks) au.read();
	vector<Q> queries(q);
	for (int i = 0; i < q; i++) queries[i].read(i);
	solve(rooks,queries);
	for (auto &au : rooks) swap(au.x,au.y);
	for (auto &au : queries) swap(au.x,au.y), swap(au.x2,au.y2);
	swap(n,m);
	solve(rooks,queries);
	for (int i = 0; i < q; i++) printf (ans[i]?"YES\n":"NO\n");
	return 0;
}