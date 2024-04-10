#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,z;
void Solve(){
	cin>>n>>z;
	int mx=0;
	for(int i=0,x;i<n;++i){
		cin>>x;
		mx=max(mx,x|z);
	}
	cout<<mx<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}