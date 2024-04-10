#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second


int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>v(n),p(n),s(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	if(k==1)
	{
		int ans=v[0];
		for(int i=1;i<n;i++)
			ans=min(ans,v[i]);
		cout<<ans<<"\n";
		return 0;
	}
	if(k==2)
	{
		p[0]=v[0];
		for(int i=1;i<n;i++)
			p[i]=min(p[i-1],v[i]);
		s[n-1]=v[n-1];
		for(int i=n-2;i>=0;i--)
			s[i]=min(s[i+1],v[i]);
		int ans;
		for(int i=0;i+1<n;i++)
		{
			int a=p[i];
			int b=s[i+1];
			int Max=max(a,b);
			if(i==0)
				ans=Max;
			else
				ans=max(ans,Max);
		}
		cout<<ans<<"\n";
		return 0;	
	}
 	int Max=v[0];	
	for(int i=1;i<n;i++)
		Max=max(Max,v[i]);
	cout<<Max<<"\n";
	return 0;
}