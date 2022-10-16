#include<bits/stdc++.h>
using namespace std;
vector<int>v[100003];
int ans[100003];
bool hop[100003];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	for(int i=0;i<n;i++)sort(v[i].begin(),v[i].end());
	int cl=0;
	for(int i=0;i<n;i++){
		if(ans[i])continue;
		cl++;
		if(cl>3){
			cout<<-1;
			return 0;
		}
		ans[i]=cl;
		memset(hop,1,sizeof(hop)); 
		for(int j=0;j<v[i].size();j++)
			hop[v[i][j]]=0;
		for(int j=0;j<n;j++)if(hop[j]&&ans[j]!=cl&&ans[j]!=0){cout<<-1;return 0;}else if(hop[j])ans[j]=cl;
	}
	if(cl<3){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<v[i].size();j++)
			if(ans[i]==ans[v[i][j]])
			{
				cout<<-1;
				return 0;
			}
	int cnt[4]={0,0,0,0};
	for(int i=0;i<n;i++)cnt[ans[i]]++;
	for(int i=0;i<n;i++)
		if(n-cnt[ans[i]]!=v[i].size()){
			cout<<-1;
			return 0;
		}
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}