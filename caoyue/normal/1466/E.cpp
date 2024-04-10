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
const ll N=5e5+7;
const ll mod=1e9+7;
ll T,n;
ll x[N],w[61][2];
bool v[N][61];
int main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d",&n);
		rep0(i,60)w[i][0]=w[i][1]=0;
		rep(i,n){
			scanf("%I64d",&x[i]);
			ll nw=x[i];
			rep0(j,60){
				v[i][j]=nw&1;
				w[j][v[i][j]]++;
				nw>>=1;
			}
		}
		ll ans=0;
		rep(i,n){
			ll s1=0,s2=0,nw=1;
			rep0(j,60){
				if(v[i][j]){
					s1=(s1+nw*w[j][1])%mod;
					s2=(s2+nw*n)%mod;
				}
				else s2=(s2+nw*w[j][1])%mod;
				nw=(nw+nw)%mod;
			}
			ans=(ans+s1*s2)%mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}