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
const int N=4007;
const int INF=1e9+7;
int n,m;
int f[N][N],l[N],s[N],c[N],g[N];
void op(int d){
	for(int i=d;i<=n+m;i++){
		rep0(k,g[i]+1){
			f[i+1][k/2]=max(f[i+1][k/2],f[i][k]+(k/2)*c[i+1]);
			g[i+1]=max(g[i+1],k/2);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&l[i]);
	rep(i,n)scanf("%d",&s[i]);
	rep(i,n+m)scanf("%d",&c[i]);
	rep(i,n+m){
		f[i][0]=0;
		rep(j,n)f[i][j]=-INF;
	}
	for(int i=n;i;i--){
		if(l[i]>m)continue;
		for(int j=g[l[i]];~j;j--)f[l[i]][j+1]=max(f[l[i]][j]+c[l[i]]-s[i],f[l[i]][j+1]);
		g[l[i]]++;
		op(l[i]);
	}
	printf("%d\n",f[n+m][0]);
	return 0;
}