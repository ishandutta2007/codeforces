#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
	int x,y;cin>>x>>y;
	if((x+y)&1)cout<<"-1 -1\n";
	else {
		int p=(x+y)/2;
		if(x>y)cout<<x-p<<' '<<y<<'\n';
		else cout<<x<<' '<<y-p<<'\n';
	}
} 

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}