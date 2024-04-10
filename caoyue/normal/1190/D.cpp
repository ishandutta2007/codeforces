#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=4e5+7;
const ll INF=1e9+7;
ll n;
ll X[N],Y[N],c[N],d[N];
map<ll,ll>mp1,mp2;
vector<ll>g[N];
ll low(ll x){return x&(-x);}
void ins(ll x,ll v){for(ll i=x;i<=n;i+=low(i))c[i]+=v;}
ll check(ll L,ll R){
	ll ans=0;
	for(ll i=R;i;i-=low(i))ans+=c[i];
	for(ll i=L-1;i;i-=low(i))ans-=c[i];
	return ans;
}
bool hv[N];
int main(){
	scanf("%I64d",&n);
	rep(i,n){
		scanf("%I64d%I64d",&X[i],&Y[i]);
		mp1[X[i]]=mp2[Y[i]]=1;
	}
	ll cnt1=0,cnt2=0,nw=0,ans=0;
	for(map<ll,ll>::iterator s=mp1.begin();s!=mp1.end();s++)mp1[s->first]=++cnt1;
	for(map<ll,ll>::iterator s=mp2.begin();s!=mp2.end();s++)mp2[s->first]=++cnt2;
	rep(i,n)X[i]=mp1[X[i]],Y[i]=mp2[Y[i]];
	rep(i,n)g[Y[i]].push_back(X[i]);
	rep(i,cnt2)sort(g[i].begin(),g[i].end());
	for(ll i=cnt2;i;i--){
		rep0(j,g[i].size()){
			if(!j)d[j]=check(1,g[i][j]-1);
			else d[j]=check(g[i][j-1]+1,g[i][j]-1);
		}
		d[g[i].size()]=check(g[i][g[i].size()-1]+1,cnt1);
		ll tot=0;
		rep0(j,g[i].size()+1)tot+=d[j];
		rep0(j,g[i].size()){
			tot-=d[j];
			ans+=(d[j]+1)*(tot+g[i].size()-j);
		}
		rep0(j,g[i].size()){
			if(hv[g[i][j]])continue;
			hv[g[i][j]]=1;
			ins(g[i][j],1);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}