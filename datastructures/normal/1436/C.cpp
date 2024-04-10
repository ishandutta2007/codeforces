#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod 1000000007
#define int long long
using namespace std;
int n,x,pos,num0,num1;
int fac[10005];
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(int x){
	return Qpow(x,mod-2);
}
inline int A(int n,int m){
	if (m>n)return 0;
	return fac[n]*inv(fac[n-m])%mod;
}
signed main(){
	cin>>n>>x>>pos;
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if (pos>=mid){
			l=mid+1;
			if (mid!=pos)num0++;
		}
		else{
			r=mid;
			if (mid!=pos)num1++;
		}
	}
	fac[0]=1;
	for (int i=1;i<=1000;i++)fac[i]=fac[i-1]*i%mod;
	int ans=A(x-1,num0)*A(n-x,num1)%mod*fac[n-1-num0-num1]%mod;
	cout<<ans<<endl;
	return 0;
}