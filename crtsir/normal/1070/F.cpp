#include<bits/stdc++.h>
using namespace std;
vector<int>v[12];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,i=0,ans=0;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	for(int i=0;i<12;i++)sort(v[i].begin(),v[i].end(),cmp);
	for(int i=0;i<v[11].size();i++)ans+=v[11][i];
	for(int i=0;i<min(v[10].size(),v[1].size());i++)
		ans+=v[10][i]+v[1][i];
	for(int i=min(v[10].size(),v[1].size());i<v[10].size();i++)
		v[0].push_back(v[10][i]);
	for(int i=min(v[10].size(),v[1].size());i<v[1].size();i++)
		v[0].push_back(v[1][i]);
	sort(v[0].begin(),v[0].end(),cmp);
	for(int i=0;i<min(v[0].size(),v[11].size());i++)
		ans+=v[0][i];
	cout<<ans;
}