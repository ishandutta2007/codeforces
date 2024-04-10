#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
using namespace std;
int n,m;
inline int pw(int a,int p){
	if (p==0)return 1;
	if (p==1)return a;
	int t=pw(a,p/2)%mod;
	t=t*t%mod;
	if (p%2)t=t*a%mod;
	return t; 
}
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n>>m;
	int ans=(pw(2,m)-1+mod)%mod;
	ans=pw(ans,n)%mod;
	cout<<ans<<endl;
	return 0;
}