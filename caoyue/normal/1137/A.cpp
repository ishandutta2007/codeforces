#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e3+7;
const int INF=1e9+7;
int a[N][N],s1[N][N],s2[N][N],g1[N][N],g2[N][N];
struct pir{int x,v;}p[N];
int n,m;
bool cmp(pir u,pir v){return u.v<v.v;}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
	rep(i,n){
		rep(j,m)p[j]=(pir){j,a[i][j]};
		sort(p+1,p+m+1,cmp);
		int nm=0;
		s1[i][p[1].x]=0;
		REP(j,2,m){
			if(p[j].v!=p[j-1].v)nm++;
			s1[i][p[j].x]=nm;
		}
		nm=g1[i][p[m].x]=0;
		for(int j=m-1;j;j--){
			if(p[j].v!=p[j+1].v)nm++;
			g1[i][p[j].x]=nm;
		}
	}
	rep(j,m){
		rep(i,n)p[i]=(pir){i,a[i][j]};
		sort(p+1,p+n+1,cmp);
		int nm=s2[p[1].x][j]=0;
		REP(i,2,n){
			if(p[i].v!=p[i-1].v)nm++;
			s2[p[i].x][j]=nm;
		}
		nm=g2[p[n].x][j]=0;
		for(int i=n-1;i;i--){
			if(p[i].v!=p[i+1].v)nm++;
			g2[p[i].x][j]=nm;
		}
	}
	rep(i,n){
		rep(j,m)printf("%d ",max(s1[i][j],s2[i][j])+max(g1[i][j],g2[i][j])+1);
		puts("");
	}
	return 0;
}