#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,f[1000005],s[1000005],dv[1000005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)dv[j]++;
	f[0]=f[1]=s[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(s[i-1]+dv[i])%M;
		s[i]=(s[i-1]+f[i])%M;
	}
	printf("%d",f[n]);
}