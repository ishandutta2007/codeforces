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
const int N=107;
const int INF=1e9+7;
int T,n,d;
int a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&d);
		rep(i,n)scanf("%d",&a[i]);
		int ans=0;
		rep(i,n)rep(j,a[i])if(d>=(i-1))d-=(i-1),ans++;
		printf("%d\n",ans);
	}
	return 0;
}