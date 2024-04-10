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
const int M=453;
const int INF=1e9+7;
const int T=449;
int m;
int st[M][N],v[N],f[M][N],w[N],g[N];
int ff(int x,int *fa){return (fa[x]==x)?x:fa[x]=ff(fa[x],fa);}

int calc(){
	scanf("%d",&m);
	rep(i,m)scanf("%d",&v[i]);
	rep0(i,v[m]+1)g[i]=0;
	rep(i,m)g[v[i]]++;
	rep(i,v[m])g[i]+=g[i-1];
	v[m+1]=v[m];
	rep0(i,T+1){
		rep(j,m+1){
			f[i][j]=j;
			st[i][j]=j;
		}
	}
	int ans=-1;
	for(int i=m;i;i--){
		w[1]=st[0][i];
		rep(j,T)w[j+1]=min(w[j],st[j][i]);
		w[0]=0;
		rep(j,T)w[j]=(v[i]-(v[w[j]]-v[i])>=0)?g[v[i]-(v[w[j]]-v[i])]:0;
		int j=T-1;
		for(;;j--){
			if(w[j]<w[j+1]&&w[j]<i){
				ans=max(ans,j);
				break;
			}
		}
		for(;~j;j--){
			if(w[j]>=w[j+1])continue;
			for(int k=ff(w[j]+1,f[j]);k<=w[j+1]&&k<=i;k=ff(k+1,f[j])){
				st[j][k]=i;
				f[j][k]=k+1;
			}
		}
	}
	return ans+1;
}
int main(){
	int n,ans=0; scanf("%d",&n);
	rep(i,n)ans^=calc();
	if(ans)puts("YES");
	else puts("NO");
	return 0;
}