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
int T,n,k;
int X[N],Y[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d%d",&X[i],&Y[i]);
		bool ans=0;
		rep(i,n){
			bool fl=1;
			rep(j,n)if(abs(X[i]-X[j])+abs(Y[i]-Y[j])>k)fl=0;
			if(fl){
				ans=1;
				break;
			}
		}
		if(ans)puts("1");
		else puts("-1");
	}
	return 0;
}