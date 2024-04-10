#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<pii,ll>pi3;
vector<ll>vec;
map<pi3,ll>ma;
ll dfs(ll pt,ll req,ll now)
{
	if(now<0||req<0)return 0;
	if(((now>>pt)<<pt)!=now)return 0;
	if(pt==vec.size())
	{
		if(req==0&&now==0)return 1;
		else return 0;
	}
	pi3 zz=make_pair(make_pair(pt,req),now);
	if(ma.count(zz))return ma[zz];
	ll s=0,t=0;
	for(ll i=pt;i<vec.size();i++)s+=(ll)vec[i]*((1LL<<i)-1),t+=vec[i];
	if(s<now||t<req)return ma[zz]=0;
	if(vec[pt]==1)return ma[zz]=dfs(pt+1,req,now-(1LL<<pt)*req)+dfs(pt+1,req-1,now-(1LL<<pt)*(req-1));
	else return ma[zz]=dfs(pt+1,req,now-(1LL<<pt)*req)+dfs(pt+1,req-1,now-(1LL<<pt)*(req-1))*2+dfs(pt+1,req-2,now-(1LL<<pt)*(req-2));
}
int main()
{
	ll num;
	scanf("%lld",&num);
	ll ans=0;
	for(ll i=0;i<=50;i++)
	{
		for(ll j=0;j<=50;j++)
		{
			ll s=1;
			for(ll k=1;k<=i;k++)s+=1LL<<k;
			for(ll k=1;k<=j;k++)s+=1LL<<k;
			if(s+(1LL<<j)-1>num)continue;
			vec.clear();
			ma.clear();
			vec.push_back(0);
			for(ll k=0;k<=min(i-2,j-2);k++)vec.push_back(2);
			for(ll k=max(1LL,min(i,j))+1;k<=max(i,j);k++)vec.push_back(1);
			ll t=0;
			for(ll k=0;k<=i+j;k++)t+=dfs(1,k,num%s-k-((1LL<<j)-1));
			ans+=t;
		}
	}
	printf("%I64d\n",ans);
}