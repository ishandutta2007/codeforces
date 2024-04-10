#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n),b;
	for(auto&i:a)cin>>i;
	map<int,int> cnt;
	for(auto i:a){
		cnt[i]++;
		if(cnt[i]<=3)b.push_back(i);
	}
	n=b.size();
	if(n>30){
		cout<<"No"<<endl;
		return;
	}
	map<int,int> vis;
	for(auto x:b)vis[x]=1;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(!vis[b[i]+b[j]+b[k]]){
					cout<<"No"<<endl;
					return;
				}
	cout<<"Yes"<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}