#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	int t;cin>>t;t=t<<1|1;
	vector<int> res(300);
	while(t--){
		string s;cin>>s;
		for(auto x:s)res[x]^=1;
	}
	for(int i=0;i<300;i++)if(res[i])cout<<(char)i<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}