#include<bits/stdc++.h>
const int N=105000;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n),b(n);
	for(auto&x:a)cin>>x;
	for(auto&x:b)cin>>x;
	sort(a.begin(),a.end()),sort(b.begin(),b.end());
	for(int i=0;i<n;i++){
		if(a[i]<=b[i]&&a[i]+1>=b[i]);
		else {
			cout<<"No\n";
			return ;
		}
	}
	cout<<"Yes\n";
}

main(){
	int t;cin>>t;while(t--)solve();
}