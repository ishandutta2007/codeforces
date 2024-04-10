#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int f[100004],n,ans;
int lcm(int a,int b){
	return (ll)a*b/__gcd(a,b)%M;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)f[i]=i-1;
	for(int i=2;i<=n;i++)
		for(int j=2;i*j<=n;j++)
			f[i*j]-=f[i];
	for(int i=1;i<=n;i++)
		for(int j=2;i*j<n;j++)
			(ans+=(ll)f[j]*lcm(i,n-i*j)%M)%=M;
	printf("%d",ans);
}