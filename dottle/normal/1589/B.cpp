#include<bits/stdc++.h>
#define int long long
const int N=105000;
using namespace std;

void solve() {
	int n,m;
	cin>>n>>m;
	int ans=0;
	if(n>m)swap(n,m);
	if(n%3==0||m%3==0)cout<<n*m/3<<endl;
	else{
		ans+=m/3*n;
		m%=3;
		ans+=n/3*m;n%=3;
		if(m==2){
			if(n==1)++ans;
			else ans+=2;
		}else if(m==1){
			if(n)++ans;
		}
		cout<<ans<<endl;
	}
}

main() {
	int t;
	cin>>t;
	while(t--)solve();
}