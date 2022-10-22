#include<bits/stdc++.h>
typedef long long ll;
const int N=250003;
int n,M,f[N],ans;
int main(){
	scanf("%d%d",&n,&M);
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=(ll)f[i-1]*i%M;
	for(int i=1;i<=n;i++)ans=(ans+(ll)f[i]*f[n-i]%M*(n-i+1)%M*(n-i+1))%M;
	printf("%d\n",ans);
	return 0;
}