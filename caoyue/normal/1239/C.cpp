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
ll n,p;
set<int>S;
struct pir{ll x,t;}t[N];
bool cmp(pir a,pir b){
	if(a.t!=b.t)return a.t<b.t;
	return a.x<b.x;
}
ll w[N],Qu[N];

int main(){
	int hd=0,ti=0;
	scanf("%I64d%I64d",&n,&p);
	rep(i,n)scanf("%I64d",&t[i].t),t[i].x=i;
	sort(t+1,t+n+1,cmp);
	ll nw=1,ts=-1;
	rep(i,n){
		while(nw<=n&&t[nw].t<ts){
			if(t[nw].x<Qu[ti])Qu[++ti]=t[nw].x;
			else S.insert(t[nw].x);
			nw++;
		}
		if(hd==ti){
			while(t[nw].t==ts){
				S.insert(t[nw].x);
				nw++;
			}
			if(S.empty()){
				ts=t[nw].t;
				while(nw<=n&&t[nw].t<=ts){
					S.insert(t[nw].x);
					nw++;
				}
			}
			Qu[++ti]=*S.begin();
			S.erase(Qu[ti]);
		}
		w[Qu[++hd]]=ts=ts+p;
	}
	rep(i,n)printf("%I64d\n",w[i]);
	return 0;
}