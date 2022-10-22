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
const int N=3507;
const int INF=1e9+7;
int a[N];
int n,m,k;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		rep(i,n)scanf("%d",&a[i]);
		k=min(k,m-1);
		int ans=0;
		rep0(i,k+1){
			int as=INF;
			rep0(j,m-k)as=min(as,max(a[i+j+1],a[n-m+1+i+j]));
			ans=max(ans,as);
		}
		printf("%d\n",ans);
	}
	return 0;
}