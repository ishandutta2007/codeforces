#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=7;
const int INF=1e9+7;
const ll p=1;
const ll q=2;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		ll n,k,fl=1; scanf("%I64d%I64d",&n,&k);
		if(!k){printf("%I64d\n",n); continue;}
		if(n>32){printf("YES %I64d\n",n-1); continue;}
		rep0(i,n){
			ll low=0,lim=0,dw=0;
			for(ll j=i;j;j--)dw+=(p<<((i-j)*2));
			for(ll j=n;j;j--)lim+=(p<<((n-j)*2));
			lim-=((q<<(n-i))-1)*dw;
			for(ll j=n;j>i;j--){
				ll d=(q<<(n-j))-1;
				low+=d;
			}
			if(low<=k&&k<=lim){
				printf("YES %I64d\n",i);
				fl=0;
				break;
			}
		}
		if(fl)puts("NO");
	}
	return 0;
}
//1 31 1000000000000000000