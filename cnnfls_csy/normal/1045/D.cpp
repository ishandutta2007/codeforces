#include <bits/stdc++.h>
using namespace std;
#define iinf 2000000000
#define linf 1000000000000000000LL
#define ulinf 10000000000000000000ull
#define MOD1 1000000007LL
#define mpr make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef unsigned short US;
typedef pair < int , int > pii;
clock_t __stt;
inline void TStart(){__stt=clock();}
inline void TReport(){printf("\nTaken Time : %.3lf sec\n",(double)(clock()-__stt)/CLOCKS_PER_SEC);}
template < typename T > T MIN(T a,T b){return a<b?a:b;}
template < typename T > T MAX(T a,T b){return a>b?a:b;}
template < typename T > T ABS(T a){return a>0?a:(-a);}
template < typename T > void UMIN(T &a,T b){if(b<a) a=b;}
template < typename T > void UMAX(T &a,T b){if(b>a) a=b;}
int n,q,fa[100005],deg[100005];
double p[100005],s[100005],ini;
vector < int > adj[100005];
void dfs(int ver){
	if(!ver) fa[ver]=-1;
	int i;
	ini+=((double)deg[ver])*p[ver];
	for(i=0;i<(int)adj[ver].size();++i){
		if(adj[ver][i]!=fa[ver]){
			fa[adj[ver][i]]=ver;
			s[ver]+=p[adj[ver][i]];
			dfs(adj[ver][i]);
		}
	}
}
int main(){
    // inputting start
    //  nm
    int i,j,k;
	scanf("%d",&n);
	ini=0;
	for(i=0;i<n;++i){
		scanf("%lf",p+i);
	}
	memset(deg,-1,sizeof(deg));
	for(i=0;i<n-1;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++deg[u];++deg[v];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    #ifdef LOCAL
        TStart();
    #endif
    // calculation start
    //  nm
    dfs(0);
	for(i=0;i<n;++i){
		ini-=p[i]*s[i];
	}
	scanf("%d",&q);
	while(q--){
		int u;
		double d;
		scanf("%d%lf",&u,&d);
		ini+=(d-p[u])*(double)deg[u];
		if(fa[u]!=-1){
			ini+=p[fa[u]]*s[fa[u]];
			s[fa[u]]+=d-p[u];
			ini-=p[fa[u]]*s[fa[u]];
		}
		ini+=p[u]*s[u];
		p[u]=d;
		ini-=p[u]*s[u];
		printf("%.5lf\n",ini+1.0);
	}
    #ifdef LOCAL
        TReport();
    #endif
    return 0;
}