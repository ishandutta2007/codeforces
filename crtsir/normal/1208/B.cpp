#include<bits/stdc++.h>
using namespace std;
int n,a[2003],cnt,ans=5865;
vector<int>v;
map<int,int>mp;
bool vis[2003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(mp[a[i]]==0&&(a[i]!=a[0]||i==0))
			mp[a[i]]=cnt++; 
	}
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		int kk=n;
		for(int j=0;j<i;j++)
			if(vis[mp[a[j]]])
				break;
			else
				vis[mp[a[j]]]++,kk--;
		for(int j=n-1;j>=i;j--)
			if(vis[mp[a[j]]])
				break;
			else
				vis[mp[a[j]]]++,kk--;
		ans=min(ans,kk);
	} 
	cout<<ans;
}