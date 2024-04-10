#include<bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define allv(V) (V).begin(),(V).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int inf=INT_MAX;
const ll infll=LONG_LONG_MAX;
const ll mod=1000000007LL;
 
int gcd(int x,int y){return y?gcd(y,x%y):x;}
 
ll n,pr[10101010];
	
bool isp(ll x)
{
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
 
vector<ll> v;
 
int main()
{
	scanf("%lld",&n);
	for(ll i=2;i*i<=n;i++)
	{
		if(pr[i]) continue;
		for(ll j=2*i;j*j<=n;j+=i) pr[j]=1;
	}
	
	//puts("hello");
	if(n==1) return !printf("1");
	if(isp(n)) return !printf("%lld",n);
	
	ll pos=2;
	while(n>1 && pos*pos<=n)
	{
		//printf("%lld\n",n);
		//printf("%lld\n",pos);
		while(pr[pos] && pos*pos<=n) pos++;
		while(n%pos==0 && n>1) n/=pos,v.pb(pos);
		pos++;
	}
 
	if(n>1) v.pb(n);
	v.erase(unique(v.begin(),v.end()),v.end());
 
	if(v.size()>1) return !printf("1");
	else printf("%lld",v[0]);
}