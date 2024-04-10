#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;
int n,ans,x,p[10005],tot;
int pw(int a,int p){
	int ans=1;
	while(p>0){
		if(p&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		p/=2;
	}
	return ans;
}
int work(int a,int b){
	int ans=1;
	while(a>0){
		ans=(ans*pw(b,a/b))%mod;
		a/=b;
	}
	return ans;
}
signed main(){
//	freopen("1228C.in","r",stdin);
//	freopen("1228C.out","w",stdout);
	cin>>x>>n;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			p[++tot]=i;
			while(x%i==0)x/=i;
		}
	}
	if(x>1)p[++tot]=x;
	ans=1;
	for(int i=1;i<=tot;i++){
		ans=(ans*work(n,p[i]))%mod;
	}
	cout<<ans<<endl;
	return 0;
}