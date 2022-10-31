#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 200005;
int a[N];

struct segt {
	int segt[4*N];
	bool lazy[4*N];
	static int l[4*N],r[4*N];
	void build(int v, int i, int j, int b) {
		l[v] = i, r[v] = j;
		//CHANGE ME
		segt[v] = lazy[v] = 0;
		if(i == j) {
			segt[v] = (a[i] & (1<<b)) != 0;
			return;
		}
		build(v<<1,i,(i+j)/2,b);
		build(v<<1|1,(i+j)/2+1,j,b);
		segt[v] = segt[v<<1] + segt[v<<1|1];
	}

	inline void prop(int v) {
		//CHANGE ME
		if(!lazy[v]) return;
		lazy[v<<1]^=lazy[v];
		lazy[v<<1|1]^=lazy[v];
		segt[v] = (r[v]-l[v]+1) - segt[v];
		lazy[v] = 0;
	}

	inline void recalc(int v) {
		//CHANGE ME
		prop(v<<1), prop(v<<1|1);
		segt[v] = segt[v<<1] + segt[v<<1|1];
	}

	void flip(int v, int i, int j) {
		if(j < l[v] || r[v] < i) return;
		if(i <= l[v] && r[v] <= j) {
			//CHANGE ME
			lazy[v] ^= 1;
			return;
		}
		prop(v);
		flip(v<<1,i,j);
		flip(v<<1|1,i,j);
		recalc(v);
	}

	int query(int v, int i, int j) {
		if(j < l[v] || r[v] < i) {
			//CHANGE ME
			return 0;
		}
		prop(v);
		if(i <= l[v] && r[v] <= j) {
			//CHANGE ME
			return segt[v];
		}
		//CHANGE ME
		return query(v<<1,i,j) + query(v<<1|1,i,j);
	}
} segs[20];

int segt::l[4*N],segt::r[4*N];

int main() {	
	int n,m;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	for(int i = 0; i < 20; ++i)
		segs[i].build(1,0,n-1,i);
	scanf("%d",&m);
	while(m--) {
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r),--l,--r;
		if(t == 1) {
			ll a = 0;
			for(int i = 0; i < 20; ++i)
				a += ll(segs[i].query(1,l,r))<<i;
			printf("%I64d\n",a);
		} else {
			int x;
			scanf("%d",&x);
			for(int i = 0; i < 20; ++i)
				if(x&(1<<i))
					segs[i].flip(1,l,r);
		}
	}
}