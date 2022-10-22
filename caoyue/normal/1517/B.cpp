#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int M=105;
const int INF=1e9+7;
int T,n,m;
struct pt{int x,y,v;}p[N];
int b[M][M],id[M][M],mn[M],vl[M];
bool h[M][M];
bool cmp(pt a,pt b){return a.v<b.v;}
int main(){
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%d%d",&n,&m);
		rep(i,n)rep(j,m)scanf("%d",&b[i][j]);
		rep(i,n){
			mn[i]=1;
			rep(j,m){
				p[++cnt]=(pt){i,j,b[i][j]};
				id[i][j]=h[i][j]=0;
			}
		}
		sort(p+1,p+cnt+1,cmp);
		rep(i,cnt){
			if(i<=m){
				id[p[i].x][p[i].y]=i;
				h[p[i].x][i]=1;
			}
			else{
				while(h[p[i].x][mn[p[i].x]])mn[p[i].x]++;
				id[p[i].x][p[i].y]=mn[p[i].x];
				h[p[i].x][mn[p[i].x]]=1;
			}
		}
		rep(i,n){
			rep(j,m)vl[id[i][j]]=b[i][j];
			rep(j,m)printf("%d ",vl[j]);
			puts("");
		}
	}
	return 0;
}