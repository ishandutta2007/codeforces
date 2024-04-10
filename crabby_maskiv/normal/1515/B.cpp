#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,m;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		ll x=sqrt(n/2);
		if(x*x*2==n){
			cout<<"YES"<<endl;
			continue;
		}
		x=sqrt(n/4);
		if(x*x*4==n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}