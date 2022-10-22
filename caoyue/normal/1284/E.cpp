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
const ll N=2507;
const ll INF=1e9+7;
ll X[N],Y[N];
struct pt{ll x,y,k;}d[N];
ll n,cz,c1,c2;
bool cmp(pt a,pt b){
	if(a.x==0)return 1;
	if(b.x==0)return 0;
	return a.y*b.x<a.x*b.y;
}
ll work(ll x){
	cz=c1=c2=0;
	rep(i,n){
		if(i==x)continue;
		if(X[i]==X[x]){
			if(Y[i]>Y[x])d[++cz]=(pt){0,Y[i]-Y[x],2},c2++;
			else d[++cz]=(pt){0,Y[i]-Y[x],1},c1++;
			continue;
		}
		if(X[i]>=X[x])d[++cz]=(pt){X[i]-X[x],Y[i]-Y[x],1},c1++;
		else d[++cz]=(pt){X[x]-X[i],Y[x]-Y[i],2},c2++;
	}
	ll nm1=0,nm2=0,as=(n-1)*(n-2)*(n-3)*(n-4)/24;
	sort(d+1,d+cz+1,cmp);
	rep(i,cz){
		ll u;
		if(d[i].k==1)u=c1-nm1-1+nm2;
		else u=nm1+c2-nm2-1;
		as=as-u*(u-1)*(u-2)/6;
		if(d[i].k==1)nm1++;
		else nm2++;
	}
	return as;
}
int main(){
	ll ans=0; 
	scanf("%I64d",&n);
	rep(i,n)scanf("%I64d%I64d",&X[i],&Y[i]);
	rep(i,n)ans+=work(i);
	printf("%I64d\n",ans);
	return 0;
}