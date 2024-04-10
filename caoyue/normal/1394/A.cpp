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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e9+7;
ll n,d,m,c1=0,c2=0;
ll a[N],s1[N],s2[N],w[N];
bool cmp(ll x,ll y){return x>y;}
int main(){
	scanf("%I64d%I64d%I64d",&n,&d,&m);
	rep(i,n){
		scanf("%I64d",&a[i]);
		if(a[i]>m)s2[++c2]=a[i];
		else s1[++c1]=a[i];
	}
	sort(s1+1,s1+c1+1,cmp);
	sort(s2+1,s2+c2+1,cmp);
	rep(i,n)s1[i]+=s1[i-1];
	rep(i,n)s2[i]+=s2[i-1];
	ll ans=0;
	rep0(i,n+1){
		if(!i)ans=max(ans,s1[n]);
		else{
			if((i-1)*(d+1)+1>n)continue;
			ans=max(ans,s2[i]+s1[n-(i-1)*(d+1)-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}