//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int n,m,dfncnt,nodev[MAXN];
int dfn[MAXN],siz[MAXN],dep[MAXN];
int seg[MAXN << 2],tag[MAXN << 2];
vector<int> G[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void DFS(int x,int fa) {
	dep[x] = dep[fa] + 1;
	siz[x] = 1;
	dfn[x] = ++dfncnt;
	for(auto to : G[x]) {
		if(to == fa) continue;
	   DFS(to,x);
	   siz[x] += siz[to];
	}
}

void pushup(int x) {seg[x] = seg[x << 1] + seg[x << 1 | 1];}

void pushdown(int x,int l,int r) {
	if(!tag[x]) return;
	seg[x << 1] += tag[x];
	seg[x << 1 | 1] += tag[x];
	tag[x << 1] += tag[x];
	tag[x << 1 | 1] += tag[x];
	tag[x] = 0;
}

void update(int x,int l,int r,int L,int R,int v) {
	if(L <= l && r <= R) {
		tag[x] += v;
		seg[x] += (r - l + 1) * v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(L <= mid) update(x << 1,l,mid,L,R,v);
	if(R > mid) update(x << 1 | 1,mid + 1,r,L,R,v);
	pushup(x);
}

int query(int x,int l,int r,int pos) {
	if(l == r) return seg[x];
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(pos <= mid) return query(x << 1,l,mid,pos);
	else return query(x << 1 | 1,mid + 1,r,pos);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	for(int i = 1;i <= n; ++i) read(nodev[i]); 
	for(int i = 1,x,y;i < n; ++i) {
		read(x); read(y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1,0);
	for(int i = 1;i <= n; ++i) {
		update(1,1,n,dfn[i],dfn[i],((dep[i] & 1) ? nodev[i] : -nodev[i]));
	}
	while(m--) {
		int opt,x,v;
		read(opt); read(x);
		//cout << opt << endl;
		if(opt == 1) {
			read(v);
			update(1,1,n,dfn[x],dfn[x] + siz[x] - 1,((dep[x] & 1) ? v : -v));
		} else printf("%d\n",query(1,1,n,dfn[x]) * ((dep[x] & 1) ? 1 : -1));
	}
	return 0;
}