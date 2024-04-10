#include<bits/stdc++.h>
using namespace std;
int T,n,k,tmp;
vector<int>v[1003],ask;
int check(int l,int r)
{
	ask.clear();
	for(int i=l;i<=r;i++)
		for(int j=0;j<v[i].size();j++)
			ask.push_back(v[i][j]);
	cout<<'?'<<' '<<ask.size();
	for(int i=0;i<ask.size();i++)
		printf(" %d",ask[i]);
	cout<<endl;
	int res;
	cin>>res;
	return res; 
}
int check2(int x)
{
	ask.clear();
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(int j=0;j<v[x].size();j++)
			if(v[x][j]==i)
			{
				ok=0;
				break;
			}
		if(ok)
			ask.push_back(i);
	}
	if(ask.size()==0)return 0;
	cout<<'?'<<' '<<ask.size();
	for(int i=0;i<ask.size();i++)
		printf(" %d",ask[i]);
	cout<<endl;
	int res;
	cin>>res;
	return res; 
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=0;i<=k;i++)
			v[i].clear();
		for(int i=0;i<k;i++)
		{
			cin>>tmp;
			while(tmp--)
			{
				int x;
				cin>>x;
				v[i].push_back(x);
			}
		}
		int maxn=check2(k);
		int l=0,r=k-1;
		while(l!=r)
		{
			int mid=(l+r)/2;
			if(check(mid+1,r)==maxn)
				l=mid+1;
			else
				r=mid;
		}
		vector<int>ans;
		for(int i=0;i<k;i++)
			if(i==l)
				ans.push_back(check2(i));
			else
				ans.push_back(maxn);
		cout<<'!';
		for(int i=0;i<k;i++)
			cout<<' '<<ans[i];
		cout<<endl;
		string s;
		cin>>s;
		if(s=="Incorrect")
			break;
	}
}