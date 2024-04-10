#include<bits/stdc++.h>
using namespace std;
map<string,pair<int,string> >mp;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		map<string,bool>vis;
		vector<string>v;
		for(int j=0;j<s.size();j++)
			for(int k=1;k+j<=s.size();k++)
				if(!vis[s.substr(j,k)])
					vis[s.substr(j,k)]=1,
					v.push_back(s.substr(j,k));
		for(int j=0;j<v.size();j++)
			mp[v[j]].first++,
			mp[v[j]].second=s;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		string s;
		cin>>s;
		if(mp[s].first)
			cout<<mp[s].first<<' '<<mp[s].second;
		else
			cout<<"0 -";
		cout<<endl;
	}
}