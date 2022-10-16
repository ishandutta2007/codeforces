#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,a,m;
inline int gcd(int a,int b){
	if (b==0)return a;
	return gcd(b,a%b);
}
inline int ola(int x){
	int ans=x;
	for (register int i=2;i*i<=x;i++){
		if (x%i==0)ans/=i,ans*=(i-1);
		while(x%i==0)x/=i;
	}
	if (x>1)ans/=x,ans*=(x-1);
	return ans;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>m;
		m/=gcd(a,m);
		cout<<ola(m)<<endl;
	}
}