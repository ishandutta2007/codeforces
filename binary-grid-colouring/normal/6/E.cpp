#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,k;
vector<pair<int,int>>vp;
multiset<int>s; 
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int j=0;
	int ans = -1;
	for(int i=0;i<n;i++)
	{
		s.insert(a[i]);
		while(*s.rbegin()-*s.begin()>k) s.erase(s.find(a[j++]));
		if(i-j+1>ans)
		{
			ans=i-j+1;
			vp.clear(); 
		}
		if(i-j+1==ans)
		{
			vp.push_back(make_pair(j+1,i+1));
		}
	}
	cout<<ans<<" "<<vp.size()<<endl;
	for(int i=0;i<vp.size();i++)
	{
		cout<<vp[i].first<<" "<<vp[i].second<<endl;
	}
	return 0;
 }