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
const int N=2e5+7;
const int INF=1e9+7;
int n,cnt=1;
int a[N],b[N][45],d[N][45];
vector<int>o[N];
int solve(int x){
	if(!o[x].size())return 0;
	memset(b[x],0,sizeof(b[x]));
	rep0(j,o[x].size()){
		int t=o[x][j],k=0;
		for(;t;k++)t>>=1;
		b[x][k]++;
	}
	rep0(i,40)if(b[x][i]>=2)d[x][i]=++cnt;
	rep0(j,o[x].size()){
		int t=o[x][j],k=0;
		for(;t;k++)t>>=1;
		if(d[x][k])o[d[x][k]].push_back(o[x][j]-(1<<(k-1)));
	}
	int Ans=0;
	rep0(i,40)if(b[x][i])Ans++;
	rep0(i,40){
		if(b[x][i]<2)continue;
		int ans=0;
		rep0(j,i)if(b[x][j]){ans++; break;}
		REP(j,i+1,35)if(b[x][j])ans++;
		Ans=max(ans+solve(d[x][i]),Ans);
	}
	return Ans;
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)o[1].push_back(a[i]);
	printf("%d\n",n-solve(1));
	return 0;
}