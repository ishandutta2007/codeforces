#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
ll n,p,k,v[200005],sum[200005];
bool check(ll m)
{
	ll sum=0,i;
	if(m>k)
	{
		for(i=0;i<m%k;i++)
			sum+=v[i];
		for(i=m%k+k-1;i<m;i+=k)
			sum+=v[i];
	}
	else if(m==k)return v[k-1]<=p;
	else
	{
		for(i=0;i<m;i++)
			sum+=v[i];
	}
	return sum<=p;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t,i,be,en,ans,j,l,count;
	cin>>t;
	while(t--)
	{
		cin>>n>>p>>k;
		sum[0]=0;
		ans=0;
		for(i=0;i<n;i++)cin>>v[i];
			sort(v,v+n);
		for(i=0;i<k-1;i++)
			sum[i+1]=v[i]+sum[i];
		//for(i=0;i<k;i++)cout<<sum[i];
		if(p<v[0])
		{
			cout<<"0\n";continue;
		}
		for(i=0;i<k;i++)
		{
			l=p;
			l-=sum[i];count=0;
			if(sum[i]>p)
				break;
			else
				{
					for(j=k+i-1;j<n;j+=k)

					{
						if(l>=v[j])
						{
						count++;l-=v[j];
						}
						else break;
					}
					ans=max(ans,i+(count)*k);
				}
				
		}
		
		/*be=1;en=n;
		while(be<=en)
		{
			ll mid=(be+en)/2;
			if(check(mid))
				be=mid+1;
			else en=mid-1;
		}
		cout<<be-1<<endl;
		*/
		cout<<ans<<endl;
	}
	return 0;
}