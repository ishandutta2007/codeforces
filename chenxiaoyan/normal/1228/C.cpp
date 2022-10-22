/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int mod=1000000007;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
bool ispr(int x){
	if(x<2)return false;
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
int n,m;
vector<int> prdiv;
signed main(){
	cin>>n>>m;
	for(int i=1;i*i<=n;i++)if(n%i==0){
		if(ispr(i))prdiv.pb(i);
		if(ispr(n/i))prdiv.pb(n/i);
	}
	sort(prdiv.begin(),prdiv.end());
	prdiv.resize(unique(prdiv.begin(),prdiv.end())-prdiv.begin());
	int ans=1;
	for(int i=0;i<prdiv.size();i++){
		int x=prdiv[i],now=1;
		while(now<=1.*LLONG_MAX/x&&now*x<=m)now*=x,(ans*=qpow(x,m/now))%=mod;
	}
	cout<<ans;
	return 0;
}