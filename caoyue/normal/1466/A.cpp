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
const int N=1007;
const int INF=1e9+7;
int T,n;
int c[N],x[N];

int main(){
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		rep(i,n)scanf("%d",&x[i]);
		rep(i,n)REP(j,i+1,n)c[x[j]-x[i]]++;
		int ans=0;
		rep(i,100)if(c[i])ans++;
		printf("%d\n",ans);
	}
	return 0;
}