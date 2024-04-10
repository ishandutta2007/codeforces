#include<bits/stdc++.h>
using namespace std;
vector<string>files;
bool vis[10010],folder[10010];
int ans1,ans2;
bool sub(int a,int b)
{
	if(files[a].size()>files[b].size())return 0;
	for(int i=0;i<files[a].size();i++)
		if(files[a][i]!=files[b][i])
			return 0;
	return 1;
}
int main()
{
	string s;
	while(cin>>s)
	{
		for(int i=4;i<s.size();i++)
			if(s[i]=='\\')
				files.push_back(s.substr(0,i+1));
		files.push_back(s);
	}
	sort(files.begin(),files.end());
	for(int i=0;i<files.size()-1;i++)
		if(files[i]==files[i+1])
			vis[i+1]=1;
	for(int i=0;i<files.size();i++)
		for(int j=0;j<files[i].size();j++)
			if(files[i][j]=='.')
				folder[i]=true;
	for(int i=0;i<files.size();i++)
	{
		int l=i,r=files.size();
		while(l<r-1)
		{
			int mid=(l+r)/2;
			if(sub(i,mid))l=mid;else r=mid;
		}
		int cnt1=0,cnt2=0;
		for(int j=i+1;j<=l;j++)
			if(!vis[j]){
				if(folder[j])
					cnt2++;
				else
					cnt1++;
			}
		ans1=max(cnt1,ans1);
		ans2=max(cnt2,ans2);
	}
	cout<<ans1<<' '<<ans2;
}