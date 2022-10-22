#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a,b,c,d;
#define ll long long
#define pll pair<ll,ll> 
pll p[N];
long long v[N];
#define fi first
#define se second
int cnt=0;
signed main(){
	scanf("%d %d/%d %d/%d",&n,&a,&b,&c,&d);
	for(int i=1;i<=n;i++){
		long long x,y;scanf("%lld%lld",&x,&y);
		cnt++;
		p[cnt].fi=a*x-b*y;
		p[cnt].se=d*y-c*x;
		if(p[cnt].fi>=0||p[cnt].se>=0)cnt--;
	}
	n=cnt;
	sort(p+1,p+1+n,[&](pll a,pll b)->bool{return a.fi==b.fi?a.se>b.se:a.fi<b.fi;});
	cnt=0;
	for(int i=1;i<=n;i++){
		if(!cnt||v[cnt]<p[i].se)v[++cnt]=p[i].se;
		else *lower_bound(v+1,v+1+cnt,p[i].se)=p[i].se;
	}
	printf("%d",cnt);
}