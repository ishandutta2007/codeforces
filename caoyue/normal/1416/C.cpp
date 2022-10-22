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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=3e5+7;
const ll INF=1e9+7;
struct Trie{
	ll to[2];
	ll sz;
}tr[N*60];
ll n,cnt=1;
ll a[N],b[40][2];
ll node(){
	tr[++cnt].sz=0;
	tr[cnt].to[0]=tr[cnt].to[1]=0;
	return cnt;
}
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,n){
		ll nw=1;
		for(ll j=30;~j;j--){
			bool t=(a[i]>>j)&1;
			if(!tr[nw].to[0])tr[nw].to[0]=node();
			if(!tr[nw].to[1])tr[nw].to[1]=node();
			if(t)b[j][1]+=tr[tr[nw].to[0]].sz;
			else b[j][0]+=tr[tr[nw].to[1]].sz;
			nw=tr[nw].to[t];
			tr[nw].sz++;
		}
	}
	ll x=0,ans=0;
	rep0(j,31){
		if(b[j][1]<b[j][0]){
			x|=(1ll<<j);
			ans+=b[j][1];
		}
		else ans+=b[j][0];
	}
	printf("%lld %lld\n",ans,x);
	return 0;
}