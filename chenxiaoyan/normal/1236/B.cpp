/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	int n,m;
	cin>>n>>m;
	cout<<qpow((qpow(2,m)-1+mod)%mod,n);
	return 0;
}