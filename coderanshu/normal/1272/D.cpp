#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long int ans,z,i,n,j;
	cin>>n;
	long int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	pair<long int,long int>p[n];
	j=0;z=0;ans=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			continue;
		}
		else
		{
			p[z].first=j;p[z].second=i-1;
			ans=max(i-j,ans);
			j=i;
			z++;
		}
	}
	p[z].first=j;p[z].second=i-1;
	z++;
	ans=max(ans,i-j);
	if(z==1)
	{
		cout<<n;
		return 0;
	}
	for(i=1;i<z;i++)
	{
		if(p[i].first==p[i].second && i<z-1)
		{
			if(a[p[i-1].second]<a[p[i].first]&& a[p[i].first]<a[p[i+1].first])
			{
				ans=max(p[i+1].second-p[i-1].first,ans);
			}
		}
		else
		{
			if(a[p[i].first+1]>a[p[i-1].second])
				ans=max(p[i].second-p[i-1].first,ans);
			else if(a[p[i-1].second-1]<a[p[i].first])
				ans=max(p[i].second-p[i-1].first,ans);
		}
	}
	cout<<ans;
	return 0;
}