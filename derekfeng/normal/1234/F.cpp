#include<bits/stdc++.h>
using namespace std;
const int B=(1<<20)-1;
char s[1000005];
int f[1048600];
int g[1048600];
int n,ans=1;
void dp(){
	for(int j=0;j<(1<<20);j++)
		for(int k=0;k<20;k++)if((1<<k)&j)
			f[j]=max(f[j],f[j^(1<<k)]);
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)s[i]-='a';
	for(int i=0;i<(1<<20);i++)g[i]=f[i]=0;
	for(int i=1;i<=n;i++){
		int msk=(1<<s[i]),j=i-1;
        f[msk]=g[msk]=max(g[msk],1);
		for(;j&&!(msk&(1<<s[j]));j--){
			msk|=(1<<s[j]);
			ans=max(ans,i-j+1);
			f[msk]=g[msk]=max(g[msk],i-j+1);
		}
	}
	dp();
	for(int i=0;i<(1<<20);i++){
		int msk=i^B,L=g[i];
		ans=max(ans,g[i]+f[msk]);
	}
	printf("%d",ans);
}