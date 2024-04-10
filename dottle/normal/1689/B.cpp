#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(auto&x:a)cin>>x;
	if(n==1){
		cout<<-1<<endl;
		return ;
	}
	vector<int> vis(n),res(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vis[j])continue;
			if(a[i]==j+1)continue;
			res[i]=j+1;vis[j]=1;
			break;
		}
	}
	if(res[n-1]==0)swap(res[n-1],res[n-2]);
	for(int i=0;i<n;i++)if(!vis[i])res[n-2]=i+1;
	for(auto x:res)cout<<x<<' ';
	cout<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}