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
const int N=1e4+7;
const int M=1e7+N;
const int INF=1e9+7;
int n,m,G,R;
int d[N],Qu[M*2],dis[N][1007];
int cc(int x,int y){return (x-1)*(G+1)+y;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m)scanf("%d",&d[i]);
	sort(d+1,d+m+1);
	scanf("%d%d",&G,&R);
	rep(i,m)rep0(j,(G+1))dis[i][j]=INF;
	int hd=M,ti=M+1;
	Qu[hd]=0;
	dis[1][0]=0;
	while(hd!=ti){
		int t=Qu[++hd];
		int v1=t/(G+1)+1,v2=t%(G+1);
		if(v1!=1&&v2+(d[v1]-d[v1-1])<=G&&dis[v1-1][v2+(d[v1]-d[v1-1])]>dis[v1][v2]){
			dis[v1-1][v2+(d[v1]-d[v1-1])]=dis[v1][v2];
			Qu[hd--]=cc(v1-1,v2+(d[v1]-d[v1-1]));
		}
		if(v1!=m&&v2+(d[v1+1]-d[v1])<=G&&dis[v1+1][v2+(d[v1+1]-d[v1])]>dis[v1][v2]){
			dis[v1+1][v2+(d[v1+1]-d[v1])]=dis[v1][v2];
			Qu[hd--]=cc(v1+1,v2+(d[v1+1]-d[v1]));
		}
		if(v2==G&&dis[v1][0]>dis[v1][v2]+1){
			dis[v1][0]=dis[v1][v2]+1;
			Qu[++ti]=cc(v1,0);
		}
	}
	int mi=INF;
	rep0(i,G+1)if(dis[m][i]<=m)mi=min(mi,dis[m][i]*(R+G)+i);
	if(mi<=m*(R+G))printf("%d\n",mi);
	else puts("-1");
	return 0;
}