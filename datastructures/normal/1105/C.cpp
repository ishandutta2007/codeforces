#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;
int n,l,r,f[1000005][3];
inline int cc(int i,int k){
	if (k==0)return i/3;
	if (k==1)return (i+2)/3;
	if (k==2)return (i+1)/3;
}
inline int calc(int l,int r,int k){
	return cc(r,k)-cc(l-1,k);
}
signed main(){
	cin>>n>>l>>r;
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<3;j++)
			for (int k=0;k<3;k++)
				f[i][j]=(f[i][j]+f[i-1][(j-k+3)%3]*calc(l,r,k))%mod;
	}
	cout<<f[n][0]<<endl;
	return 0;
}