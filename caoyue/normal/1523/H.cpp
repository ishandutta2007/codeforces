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
const int N=2e4+7;
const int INF=1e9+7;
int n,q;
int a[N],f[20][N][34],mn[N*2],p[34],np[34];
struct pir{int x,v;}h[22][N];
pir mer(pir a,pir b){return (a.v>b.v)?a:b;}
int check(int L,int R){
	int k=mn[R-L+1];
	return mer(h[k][L],h[k][R-(1<<k)+1]).x;
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)h[0][i]=(pir){i,i+a[i]};
	for(int i=1;(1<<i)<=n;i++){
		rep(j,n-(1<<i)+1)h[i][j]=mer(h[i-1][j],h[i-1][j+(1<<(i-1))]);
		REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
	}
	rep(i,n)rep0(j,32)f[0][i][j]=min(n,i+a[i]+j);
	rep0(i,14){
		rep(j,n){
			rep0(o,32)f[i+1][j][o]=j; 
			rep0(k,32){
				int x=check(j,f[i][j][k]);
				REP(o,k,31)f[i+1][j][o]=max(f[i+1][j][o],f[i][x][o-k]);
			}
		}
	}
	rep(i,q){
		int l,r,u,ans=0; scanf("%d%d%d",&l,&r,&u);
		if(l==r){
			puts("0");
			continue;
		}
		rep0(j,32)p[j]=l;
		for(int j=14;~j;j--){
			rep0(k,32)np[k]=l;
			rep0(k,32){
				int x=check(l,p[k]);
				REP(o,k,31)np[o]=max(np[o],f[j][x][o-k]);
			}
			if(np[u]<r){
				ans+=(1<<j);
				rep0(k,32)p[k]=np[k];
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}