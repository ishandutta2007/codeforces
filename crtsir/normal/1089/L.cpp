#include<bits/stdc++.h>
using namespace std;
vector<int>v[100003],tot;
long long ans,cnt;
int n,m,a[100003],b[100003];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i],
		v[a[i]].push_back(b[i]);
	cnt=m;
	for(int i=0;i<=m;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		if(v[i].size()>1){
			for(int j=1;j<v[i].size();j++)
				tot.push_back(v[i][j]);
		}
		if(v[i].size())cnt--;
	}
	sort(tot.begin(),tot.end());
	for(int i=0;i<cnt;i++)ans+=tot[i];
	cout<<ans;
}