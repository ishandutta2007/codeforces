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
const ll N=1049999;
const ll INF=1e9+7;
ll T;
ll n,g,h;
ll a[N];
vector<ll>px[N],w;

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&h,&g);
		n=(1<<h)-1;
		w.clear();
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,n)px[i].clear();
		for(ll i=n;i>=(1<<(g-1));i--)px[i].push_back(a[i]);
		for(ll i=(1<<(h-1))-1;i>=(1<<(g-1));i--){
			ll nw1=0,nw2=0;
			while(nw1<px[i*2].size()&&nw2<px[i*2+1].size()){
				if(px[i*2][nw1]>px[i*2+1][nw2]){
					px[i].push_back(px[i*2][nw1]);
					nw1++;
				}
				else{
					px[i].push_back(px[i*2+1][nw2]);
					nw2++;
				}
			}
			while(nw1<px[i*2].size())px[i].push_back(px[i*2][nw1]),nw1++;
			while(nw2<px[i*2+1].size())px[i].push_back(px[i*2+1][nw2]),nw2++;
		}
		ll ans=0;
		for(ll i=(1<<g)-1;i>=(1<<(g-1));i--)ans+=px[i][px[i].size()-1];
		for(ll i=(1<<(g-1))-1;i;i--){
			px[i].push_back(a[i]);
			ll mi=max(px[i*2][px[i*2].size()-1],px[i*2+1][px[i*2+1].size()-1]),nw1=0,nw2=0;
			while(nw1<px[i*2].size()&&nw2<px[i*2+1].size()){
				if(px[i*2][nw1]>px[i*2+1][nw2]){
					if(px[i*2][nw1]<=mi)break;
					px[i].push_back(px[i*2][nw1]);
					nw1++;
				}
				else{
					if(px[i*2+1][nw2]<=mi)break;
					px[i].push_back(px[i*2+1][nw2]);
					nw2++;
				}
			}
			ans+=px[i][px[i].size()-1];
			while(nw1<px[i*2].size()-1)w.push_back(i*2),nw1++;
			while(nw2<px[i*2+1].size()-1)w.push_back(i*2+1),nw2++;
		}
		rep(i,px[1].size()-1)w.push_back(1);
		printf("%lld\n",ans);
		for(int i=w.size()-1;~i;i--)printf("%lld ",w[i]);
		puts("");
	}
	return 0;
}