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
int T,n;
int a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int eq=0;
		rep(i,n-1)if(a[i]==a[i+1])eq++;
		if(eq<=1){
			puts("0");
			continue;
		}
		int mi=n+1,mx=0;
		rep(i,n-1){
			if(a[i]==a[i+1]){
				mi=min(mi,i);
				mx=max(mx,i);
			}
		}
		printf("%d\n",max(1,mx-mi-1));
	}
	return 0;
}