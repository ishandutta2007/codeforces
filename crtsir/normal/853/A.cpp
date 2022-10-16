#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,res[300002];
set<long long>s;
pair<long long,long long>c[300002];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].first;
		c[i].second=i;
		s.insert(i+k);
	}
	sort(c+1,c+n+1);
	for(int i=n;i>0;i--)
	{
		set<long long>::iterator it=s.lower_bound(c[i].second);
		ans=ans+(*it-c[i].second)*c[i].first;
		res[c[i].second]=*it;
		s.erase(it);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
}