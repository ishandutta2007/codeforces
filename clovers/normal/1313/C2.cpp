#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=500010;
typedef pair<ll,ll> pii;

ll n,a[N],sum=INF,ans[N];
priority_queue<pii> b,f;
ll fx[N],bx[N];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		fx[i]=fx[i-1];
		ll num=1;
		while(!f.empty())
		{
			pii tmp=f.top();
			if(tmp.first<=a[i]) break;
			f.pop();
			fx[i]+=tmp.second*(tmp.first-a[i]);
			num+=tmp.second;
		}
		f.push(make_pair(a[i],num));
	}
	for(int i=n;i>=1;i--)
	{
		bx[i]=bx[i+1];
		ll num=1;
		while(!b.empty())
		{
			pii tmp=b.top();
			if(tmp.first<=a[i]) break;
			b.pop();
			bx[i]+=tmp.second*(tmp.first-a[i]);
			num+=tmp.second;
		}
		b.push(make_pair(a[i],num));
	}
	
	ll now=INF,pos=-1;
	for(int i=1;i<=n;i++) 
	{
		//cout<<fx[i]<<" "<<bx[i]<<endl;
		if(now>bx[i]+fx[i]) 
		{
			now=bx[i]+fx[i];
			pos=i;
		}
	}
	for(int i=pos+1;i<=n;i++)
	{
		if(a[i]>a[i-1]) a[i]=a[i-1];
	}
	for(int i=pos-1;i>=1;i--)
	{
		if(a[i]>a[i+1]) a[i]=a[i+1];
	}
	
	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}