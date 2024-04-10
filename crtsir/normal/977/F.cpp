#include"bits/stdc++.h"
using namespace std;
int n,a[200005],par[200005],d[200005];
map<int,int>mp;
int main()
{
	cin>>n;
	memset(par,-1,sizeof(par));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(mp.count(a[i]-1))
		{
			d[i]=d[mp[a[i]-1]]+1;
			par[i]=mp[a[i]-1];
		}
		else
			d[i]=1;
		mp[a[i]]=i;
	}
	int best=0;
	vector<int>ans;
	for(int i=0;i<n;i++)
		if(d[i]>d[best])
			best=i;
	for(int i=best;i!=-1;i=par[i])
		ans.push_back(i);
	reverse(ans.begin(),ans.end());
	cout<<d[best]<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]+1<<' ';
}