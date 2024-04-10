#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef pair<db,int> pdi;
#define fi first
#define se second
#define mkp make_pair
int n,m,K,a[100004],t,x,p,q[100004];
vector<pdi>v[3][100004],f;
vector<int>ans;
bool ok[100004];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>K>>n>>m;
	for(int i=1;i<=K;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>t>>p>>x,v[t-1][p].push_back(mkp(x,i)),q[i]=t-1;
	for(int i=1;i<=K;i++){
		sort(v[0][i].begin(),v[0][i].end());
		if(v[0][i].empty())continue;
		if(v[0][i].back().fi<=a[i])continue;
		v[1][i].push_back(mkp(v[0][i].back().fi-a[i],v[0][i].back().se));
	}
	for(int i=1;i<=K;i++){
		sort(v[1][i].begin(),v[1][i].end());
		reverse(v[1][i].begin(),v[1][i].end());
		if(v[1][i].empty())continue;
		db cur=a[i],cc;
		for(auto x:v[1][i]){
			db cc=cur+x.fi;
			f.push_back(mkp(cc/cur,x.se));
			cur=cc;
		}
	}
	for(int i=1;i<=K;i++)
		for(auto x:v[2][i])f.push_back(x);
	sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
	int num=0;
	for(int i=0;i<m&&i<f.size();i++)num++,ok[f[i].se]=1;
	cout<<num<<"\n";
	for(int i=1;i<=n;i++)if(ok[i]&&q[i]==0)cout<<i<<" ";
	for(int i=1;i<=n;i++)if(ok[i]&&q[i]==1)cout<<i<<" ";
	for(int i=1;i<=n;i++)if(ok[i]&&q[i]==2)cout<<i<<" ";
}