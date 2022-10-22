#include<bits/stdc++.h>
using namespace std;
int f[4000005],n,M;
int s[4000005],d[4000005];
int main(){
	scanf("%d%d",&n,&M);
	f[1]=1;
	for(int i=1;i<=n;i++)d[i]=0;
	for(int i=1;i<=n;i++){
		(f[i]+=s[i-1])%=M;
		d[i]=(d[i-1]+d[i])%M;
		(f[i]+=d[i])%=M;
		s[i]=(s[i-1]+f[i])%M;
		for(int j=2;i*j<=n;j++){
			(d[j*i]+=f[i])%=M;
			if((i+1)*j<=n)(d[(i+1)*j]+=M-f[i])%=M;
		}
	}
	printf("%d",f[n]);
}