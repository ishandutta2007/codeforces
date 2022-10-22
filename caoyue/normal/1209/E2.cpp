#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=27;
const int M=4445;
const int INF=1e9+7;
struct pir{int x,v;}p[M];
int a[N][M],c[N][N],mx[M],f[N][M],w[M];
int n,m;
bool cmp(pir a,pir b){return a.v>b.v;}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
		rep(i,m){
			mx[i]=0;
			rep(j,n)mx[i]=max(mx[i],a[j][i]);
			p[i]=(pir){i,mx[i]};
		}
		sort(p+1,p+m+1,cmp);
		int k=min(n,m);
		rep(i,k)rep0(j,n)c[i][j]=a[j+1][p[i].x];
		memset(f,0,sizeof(f));
		rep(i,k){
			rep(j,n){
				int p=c[i][0];
				rep0(t,n)c[i][t]=c[i][t+1];
				c[i][n-1]=p;
				rep0(o,(1<<n))w[o]=f[i-1][o];
				rep0(o,(1<<n))rep0(g,n)if(!((o>>g)&1))w[o|(1<<g)]=max(w[o|(1<<g)],w[o]+c[i][g]);
				rep0(o,(1<<n))f[i][o]=max(f[i][o],w[o]);
			}
		}
		printf("%d\n",f[k][(1<<n)-1]);
	}
	return 0;
}