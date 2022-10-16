#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
int main()
{
	cin>>n>>s>>t;
	vector<int>v;
	for(int i=0;i<n;i++)
		if(s[i]!=t[i])
			v.push_back(s[i]-t[i]);
	int cntt=0;
	for(int i=0;i<v.size();i++)
		cntt+=v[i];
	if(cntt)
	{
		cout<<-1;
		return 0;
	}
	int ans=0,cnt=0;
	for(int i=0;i<v.size();i++)
	{
		cnt=max(0,cnt+v[i]),
		ans=max(ans,cnt);
	}
	cnt=0;
	for(int i=0;i<v.size();i++)
	{
		cnt=max(0,cnt-v[i]);
		ans=max(ans,cnt);
	}
	cout<<ans;
}