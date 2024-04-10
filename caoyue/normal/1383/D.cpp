#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=257;
const int INF=1e9+7;
int a[N][N],g[N*N],ex[N*N],ey[N*N],b[N][N],c[N][N];
struct pir{int x,y;}Qu[N*N];
int n,m,c1=0,c2=0;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
	rep(i,n){
		int mx=0;
		rep(j,m)mx=max(mx,a[i][j]);
		g[mx]|=1;
	}
	rep(i,m){
		int mx=0;
		rep(j,n)mx=max(mx,a[j][i]);
		g[mx]|=2;
	}
	rep(i,n*m){
		if(g[i]==3){
			c1++;
			c2++;
			ex[i]=ey[i]=c1;
		}
	}
	for(int i=n*m;i;i--){
		if(g[i]==1){
			c1++;
			ex[i]=c1;
			ey[i]=ey[n*m];
		}
		if(g[i]==2){
			c2++;
			ey[i]=c2;
			ex[i]=ex[n*m];
		}
	}
	int hd=0,ti=0;
	for(int i=n*m;i;i--){
		if(!g[i]){
			pir o=Qu[++hd];
			ex[i]=o.x;
			ey[i]=o.y;
		}
		else b[ex[i]][ey[i]]=2;
		if(ex[i]>1){
			b[ex[i]-1][ey[i]]++;
			if(b[ex[i]-1][ey[i]]==2)Qu[++ti]=(pir){ex[i]-1,ey[i]};
		}
		if(ex[i]<n){
			b[ex[i]+1][ey[i]]++;
			if(b[ex[i]+1][ey[i]]==2)Qu[++ti]=(pir){ex[i]+1,ey[i]};
		}
		if(ey[i]>1){
			b[ex[i]][ey[i]-1]++;
			if(b[ex[i]][ey[i]-1]==2)Qu[++ti]=(pir){ex[i],ey[i]-1};
		}
		if(ey[i]<m){
			b[ex[i]][ey[i]+1]++;
			if(b[ex[i]][ey[i]+1]==2)Qu[++ti]=(pir){ex[i],ey[i]+1};
		}
	}
	rep(i,n*m)c[ex[i]][ey[i]]=i;
	rep(i,n){
		rep(j,m)printf("%d ",c[i][j]);
		puts("");
	}
	return 0;
}