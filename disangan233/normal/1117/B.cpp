#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
ll n,m,k,ans,a[200005],maxn,now;
int main()
{
	cin>>n>>m>>k;
	for(re i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<ll>());
	ll t=m/(k+1),x=t*k,y;
	if(t*(k+1)!=m) x+=m-t*(k+1);y=t;
	cout<<a[1]*x+a[2]*y;
	return 0;
}