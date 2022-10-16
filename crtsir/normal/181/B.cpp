#include<bits/stdc++.h>
using namespace std;
int n,x[3001],y[3001],ans;
set<pair<int,int> >s;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		s.insert(make_pair(x[i],y[i]));
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if((x[i]+x[j])%2==0&&(y[i]+y[j])%2==0)
			{
				ans+=(s.find(make_pair((x[i]+x[j])/2,(y[i]+y[j])/2))!=s.end());
			}
	cout<<ans;
}