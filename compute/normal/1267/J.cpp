#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;

int cnt[maxn];
int cntcnt[maxn];
vector<int> v;


ll exgcd(ll a,ll b,ll& x,ll& y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}

bool check(int s)
{
	for(int x: v)
		if((x%s)>(x/s))	return false;
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		v.clear();
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			cnt[i]=0,cntcnt[i]=0;
		for(int i=1,x;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		int mn=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i])
			{
				cntcnt[cnt[i]]++;
				if(cntcnt[cnt[i]]==1)
				{
					v.push_back(cnt[i]);
					mn=min(mn,cnt[i]);
				}
			}
		}

		int sqr=sqrt(mn),ans=-1;
		bool flag=false;
		if(check(mn+1))
		{
			ans=max(ans,mn+1);
			flag=true;
		}
		if(!flag)
		{
			for(int i=1;i<=sqr;i++)
			{
				if(mn%i==0)
				{
					if(check(mn/i))
					{
						ans=max(ans,mn/i);
						flag=true;
						break;
					}
					if(check(mn/i-1))
					{
						ans=max(ans,mn/i-1);
						flag=true;
						break;
					}
				}
				else
				{
					if(check(mn/i))
					{
						ans=max(ans,mn/i);
						flag=true;
						break;
					}
				}
			}
		}

		if(!flag)
		{
			for(int s=sqr+1;s>=1;s--)
			{
				if(check(s))
				{
					ans=max(ans,s);
					flag=true;
					break;
				}
			}
		}

		if(!flag)	ans=1;
		else		ans++;

		ll a=ans,b=ans-1,x,y;
		ll d=exgcd(a,b,x,y);

		ll res=0;
		for(int i:v)
		{
			ll xx=x*i,yy=y*i;
			yy=(yy%a+a)%a;
			xx=(i-yy*(ans-1))/ans;
			res+=(xx+yy)*cntcnt[i];
		}
		printf("%lld\n",res);


	}
}