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
const ll N=1e6+7;
const ll INF=1e17+7;
const ll T=1000000;
ll k;
ll F[6],V[6]={3,30,300,3000,30000,300000},V0[6]={1,10,100,1000,10000,100000};
ll f[N],nf[N],hd[N],ti[N];
struct pir{ll x,v;};
vector<pir>Qu[N];

int main(){
	scanf("%I64d",&k);
	rep0(i,6)scanf("%I64d",&F[i]);
	rep0(i,T)f[i]=-INF;
	f[0]=0;
	rep0(i,6){
		rep0(j,T)nf[j]=-INF;
		ll b=T/V[i]+1;
		rep0(j,V[i]){
			Qu[j].clear();
			rep(o,b+3)Qu[j].push_back((pir){0,0});
			hd[j]=ti[j]=0;
		}
		rep0(j,T){
			ll q=j%V[i],vj=-j/V[i]*F[i]+f[j];
			while(hd[q]!=ti[q]){
				if(Qu[q][ti[q]].v>vj)break;
				ti[q]--;
			}
			Qu[q][++ti[q]]=(pir){j,vj};
			ll h=j%V0[i];
			rep0(o,3){
				while(hd[h]!=ti[h]){
					if(j-Qu[h][hd[h]+1].x<=9ll*(k-1)*V0[i])break;
					hd[h]++;
				}
				if(hd[h]!=ti[h])nf[j]=max(nf[j],(j-Qu[h][hd[h]+1].x)/V[i]*F[i]+f[Qu[h][hd[h]+1].x]);
				h+=V0[i];
			}
			rep(o,9){
				ll h=9ll*(k-1)*V0[i]+o*V0[i],vl=3ll*F[i]*(k-1)+(ll)((o%3)==0)*(o/3ll*F[i]);
				if(h>j)break;
				nf[j]=max(nf[j],f[j-h]+vl);
			}
		}
		rep0(j,T)f[j]=nf[j];
	}
	ll Q; scanf("%I64d",&Q);
	while(Q--){
		ll op; scanf("%I64d",&op);
		printf("%I64d\n",f[op]);
	}
	return 0;
}