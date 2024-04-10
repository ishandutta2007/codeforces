#include<iostream>
#include<cstring>
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
const ll N=2e5+7;
const ll INF=1e9+7;
struct pir{ll x,y;}p[N];
ll n,ans=0;
bool cmp(pir u,pir v){return u.x+u.y>v.x+v.y;}

int main(){
	scanf("%I64d",&n);
	ll cnt=0,ans=0;
	rep(i,n){
		ll a,b,c,d; scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
		if(a<=d&&b<=c)continue;
		if(a+b>c+d){
			p[++cnt]=(pir){a,b};
			p[++cnt]=(pir){c,d};
		}
		else if(a>=d) p[++cnt]=(pir){a-d,d-a};
		else p[++cnt]=(pir){c-b,b-c};
	}
	sort(p+1,p+cnt+1,cmp);
	rep(i,cnt)if(i&1)ans+=p[i].x;else ans-=p[i].y;
	printf("%I64d\n",ans);
	return 0;
}