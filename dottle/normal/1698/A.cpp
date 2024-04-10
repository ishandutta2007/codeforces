#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	int s=0;
	for(auto&i:a)cin>>i,s^=i;
	cout<<a[0]<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}