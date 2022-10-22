#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
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
ll sm(ll x){
	if(x&1)return x/2-x;
	return x/2;
}
int main(){
	ll q; scanf("%I64d",&q);
	while(q--){
		ll l,r; scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",sm(r)-sm(l-1));
	}
	return 0;
}