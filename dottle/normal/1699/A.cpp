#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	if(n&1){
		cout<<-1<<endl;
	}else{
		cout<<(n/2^1)<<' '<<(n/2^1)<<' '<<1<<endl;
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}