#include<set>
#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int k,n;cin>>k>>n;
	map<string,vector<int> >m;
	map<string,vector<int> >::iterator it;
	
	string s;int val,ans=0,maxind=0;
	for(int i=1;i<=k;++i) cin>>s>>val,m[s].push_back(val);
	for(it=m.begin();it!=m.end();++it) sort(it->second.begin(),it->second.end());
	
	for(it=m.begin();it!=m.end();++it)
	{
		string s=it->first,rev=s;
		reverse(rev.begin(),rev.end());
		if(s==rev){
			for(int v1,v2,val;m[s].size() > 1;ans+=max(val,0))
			{
				v1=m[s].back();m[s].pop_back();
				v2=m[s].back();m[s].pop_back();
				val=v1+v2;
				if(v1>0&&v2<0) maxind=max(maxind,v1-max(val,0));
			}
			if(m[s].size()) maxind=max(maxind,m[s].back()),m[s].pop_back();
		}	
		else for(;!m[s].empty()&&!m[rev].empty();m[s].pop_back(),m[rev].pop_back()) ans+=max(m[s].back()+m[rev].back(),0);
	}
	cout<<ans+maxind;
	return 0;
}