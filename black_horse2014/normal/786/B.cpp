#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}
const LL INF=1LL<<60;
LL d[1<<20];
typedef pair<long long, long long> P;
vector<P> G[1<<20];
int N,size;
void add(int t,int v,int l,int r,int w,int k,int a,int b) {
	if(b<=l||r<=a) return;
	if(l<=a&&b<=r) {
		if(t==2) {
			G[v+N-1+size].push_back(P(w,k+size));
		}else {
			G[k].push_back(P(w,v+N-1));
		}
		return;
	}
	add(t,v,l,r,w,k*2+1,a,(a+b)/2);
	add(t,v,l,r,w,k*2+2,(a+b)/2,b);
}

int main() {
	int n,q,s;
	scanf("%d %d %d",&n,&q,&s);s--;
	N=1;
	while(N<n) N*=2;
	size=2*N-1;
	for(int i=size-1;i>=0;i--) {
		d[i]=INF;
		d[i+size]=INF;
		if(i>=N-1) {
			G[i].push_back(P(0,i+size));
			G[i+size].push_back(P(0,i));
		}
		if(i>0) {
			int par=(i-1)/2;
			G[i].push_back(P(0,par));
			G[par+size].push_back(P(0,i+size));
		}
	}
	for(int i=0;i<q;i++) {
		int t,v,u,l,r,w;
		scanf("%d",&t);
		if(t==1) {
			scanf("%d %d %d",&v,&u,&w);v--;u--;
			G[v+N-1].push_back(P(w,u+N-1));
		}else {
			scanf("%d %d %d %d",&v,&l,&r,&w);v--;l--;
			add(t,v,l,r,w,0,0,N);
		}
	}
	priority_queue<P,vector<P>,greater<P> > Q;
	Q.push(P(0,s+N-1));
	d[s+N-1]=0;
	while(!Q.empty()) {
		P p=Q.top();Q.pop();
		LL dist=p.first;
		int v=p.second;
		if(d[v]<dist) continue;
		for(int i=0;i<G[v].size();i++) {
			LL cost=G[v][i].first;
			int u=G[v][i].second;
			if(dist+cost<d[u]) {
				d[u]=dist+cost;
				Q.push(P(d[u],u));
			}
		}
	}
	for(int i=0;i<n;i++) {
		if(d[i+N-1]==INF) printf("-1 "); else printf("%lld ",d[i+N-1]);
	}
	printf("\n");
}