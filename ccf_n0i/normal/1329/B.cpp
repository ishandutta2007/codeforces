#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int t,n,mod,i,s;
vector<int> v;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>mod;
		s=1;
		for(i=1;n;i<<=1){
			s=1ll*s*(min(i,n)+1)%mod;
			n-=min(i,n);
		}
		cout<<(s-1+mod)%mod<<endl;
	}
	return 0;
}