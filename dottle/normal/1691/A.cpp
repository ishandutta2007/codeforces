#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	int x=0,y=0;
	int n;cin>>n;
	while(n--){
		int z;cin>>z;
		(z%2?x:y)++;
	}cout<<min(x,y)<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}