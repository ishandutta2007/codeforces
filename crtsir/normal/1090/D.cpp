#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int>a[100003];
int cnt[100003],ans[100003];
vector<int>v[100003];
bool vis[100003];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>a[i].first>>a[i].second,
		cnt[--a[i].first]++,
		cnt[--a[i].second]++,
		v[a[i].first].push_back(a[i].second),
		v[a[i].second].push_back(a[i].first);
	if(m>=n*(n-1)/2){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	int k=0;
	while(cnt[k]==n-1)k++;
	for(int i=0;i<cnt[k];i++)
		ans[v[k][i]]=i+1;
	ans[k]=cnt[k]+1;
	if(cnt[k]==n){
		cout<<"HEHE";
		return 0;
	}
	int add=1;
	for(int i=0;i<n;i++)if(!ans[i])ans[i]=ans[k]+add,add++;
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	ans[k]++;
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}