#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,mod=1e9+7;
int n,m,f[N];
int main(){
	scanf("%d%d",&n,&m);
	f[0]=f[1]=1;
	for(int i=2;i<=max(n,m);i++)f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d\n",((f[n]+f[m]-1)%mod*2%mod+mod)%mod);
	return 0;
}