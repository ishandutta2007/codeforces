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
const int INF=1e9+7;
int T;
int a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		int n,z,ans=0; scanf("%d%d",&n,&z);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)ans=max(ans,a[i]|z);
		printf("%d\n",ans);
	} 
	return 0;
}