#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		ll x;cin>>x;
		if(x<15){
			cout<<"NO"<<endl;
			continue;
		}
		if(x%14<7&&x%14>0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}