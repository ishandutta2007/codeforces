#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){

	int n,k;cin>>n>>k;
	vector<int> a(n);
	for(auto&i:a)cin>>i;
	if(k==1){
		cout<<(n-1)/2<<endl;
		return;
	}
	int res=0;
	for(int i=1;i+1<n;i++){
		if(a[i]>a[i-1]+a[i+1])res++;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}