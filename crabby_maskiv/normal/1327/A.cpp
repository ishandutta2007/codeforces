#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		if(n<m*m) cout<<"NO"<<endl;
		else if((n&1)^(m&1)) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	} 
	return 0;
}