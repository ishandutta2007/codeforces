#include<bits/stdc++.h>
using namespace std;
vector<int>pos[26];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<26;i++)pos[i].push_back(-1);
	for(int i=0;i<s.size();i++)pos[s[i]-'a'].push_back(i);
	for(int i=0;i<26;i++)pos[i].push_back(s.size());
	int ans=INT_MAX;
	for(int i=0;i<26;i++)
	{
		int a=0;
		for(int j=0;j<pos[i].size();j++)
			a=max(a,pos[i][j]-pos[i][j-1]);
		ans=min(a,ans);
	}
	cout<<ans;
}