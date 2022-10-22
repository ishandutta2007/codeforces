#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
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
ll f[65][105];
ll n=58,m=50;
bool query(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	char s[15]; scanf("%s",s);
	if(s[0]=='F')return 0;
	return 1;
}
ll solve(ll L,ll R,ll x,ll v,ll st){
	if(R-L==1)return L;
	if(x<2){
		query(v);
		return solve(L,R,x+1,v,st-1);
	}
	ll w=min(L+f[st-1][x-2],R-1);
	bool t=query(w);
	if(!t)return solve(L,w,x-2,v,st-1);
	else return solve(w,R,x+1,v,st-1);
}
int main(){
	rep0(i,m+1)f[0][i]=1;
	rep(i,n){
		rep0(j,m+1){
			if(j<2)f[i][j]=f[i-1][j+1];
			else f[i][j]=f[i-1][j+1]+f[i-1][j-2];
		}
	}
	int T; scanf("%lld",&T);
	while(T--){
		ll ans=-1;
		rep0(i,47){
			bool t=query(1ll<<i);
			if(!t){
				if(i<=1){
					ans=(1ll<<i)-1;
					break;
				}
				ans=solve((1ll<<(i-1)),(1ll<<i),0,(1ll<<(i-1)),58);
				break;
			}
		}
		if(ans<0)ans=solve(1ll<<46,100000000000001ll,0,(1ll<<46),58);
		printf("! %lld\n",ans);
	}
	return 0;
}