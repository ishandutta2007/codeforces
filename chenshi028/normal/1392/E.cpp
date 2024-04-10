#include<iostream>
using namespace std;
const int o=30;
#define int long long
int n,q,k,x,y;
signed main(){
	cin>>n;
	for(int i=1;i<=n;++i,cout<<endl) for(int j=1;j<=n;++j) cout<<((i&1)?0:(1ll<<(i+j-1)))<<" ";
	cout.flush();
	cin>>q;while(q--){
		cin>>k;cout<<"1 1\n";
		for(x=1,y=1;(x^n)|(y^n);cout<<x<<" "<<y<<endl) if(((k>>(x+y))&1)^(x&1)){++y;continue;}else ++x;
		cout.flush();
	}
	return 0;
}