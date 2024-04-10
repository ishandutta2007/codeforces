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
const int N=7;
const int INF=1e9+7;
int T;
ll f[N];
void solve(ll x,ll y,ll nw){
	if(y==(1ll<<(x-1))){
		rep(i,x)printf("%lld ",x-i+1+nw);
		puts("");
		return;
	}
	rep(i,x-1){
		if((1ll<<(x-i-1))>=y){
			for(int j=i;j;j--)printf("%lld ",j+nw);
			solve(x-i,y,nw+i);
			return;
		}
		y-=(1ll<<(x-i-1));
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		ll n,k; scanf("%lld%lld",&n,&k);
		ll nw=0;
		if(n<62){
			if((1ll<<(n-1))<k){
				puts("-1");
				continue;
			}
		}
		while(n>62){
			n--;
			nw++;
			printf("%lld ",nw);
		}
		solve(n,k,nw);
	}
	return 0;
}