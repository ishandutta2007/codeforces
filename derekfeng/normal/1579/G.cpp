#include<bits/stdc++.h>
using namespace std;
const int M=2e4;
int n,a[10004],T,f[20004],nf[20004];
void sol(){
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0]=0;
	for(int i=1;i<=n;i++){
		memset(nf,0x3f,sizeof(nf));
		for(int j=0;j<=M;j++)if(f[j]<=M){
			int x=j,y=f[j]-j;
			if(x<a[i])nf[0]=min(nf[0],f[j]+a[i]-x);
			else nf[x-a[i]]=min(nf[x-a[i]],f[j]);
			if(y<a[i])nf[f[j]+a[i]-y]=min(nf[f[j]+a[i]-y],f[j]+a[i]-y);
			else nf[x+a[i]]=min(nf[x+a[i]],f[j]);
		}
		memcpy(f,nf,sizeof(f));
	}
	int ans=1e9;
	for(int i=0;i<=M;i++)ans=min(ans,f[i]);
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}