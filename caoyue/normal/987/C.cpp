#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
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
const int N=3e3+7;
const int INF=1e9+7;
int n,ans=INF;
int s[N],c[N],f[N][3];

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&s[i]);
	rep(i,n)scanf("%d",&c[i]);
	rep(i,n){
		f[i][0]=c[i];
		f[i][1]=f[i][2]=INF;
		rep(j,i-1){
			if(s[j]>=s[i])continue;
			rep(k,2)f[i][k]=min(f[i][k],f[j][k-1]+c[i]);
		}
		ans=min(ans,f[i][2]);
	}
	if(ans!=INF)printf("%d\n",ans);
	else puts("-1");
	return 0;
}