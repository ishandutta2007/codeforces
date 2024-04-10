#include<bits/stdc++.h>
using namespace std;
int n,a[512],s[512],ns[512];
int f[512][512],g[512][512];
void chmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,0xdf,sizeof(f));
	memset(g,0xdf,sizeof(g));
	g[0][0]=0;
	for(int t=0;t<n;t++){
		memset(s,0xdf,sizeof(s));
		for(int i=0;i<=n;i++){
			memcpy(ns,s,sizeof(s));
			for(int j=t;~j;j--){
				int x=max(f[i][j],g[i][j]);
				chmax(g[i][j+1],x);
				chmax(s[j+1],x);
				f[i][j]+=a[i];
			}
			if(i>t)
				for(int j=i-t-1;j<=t+1;j++)
					chmax(f[i][j-(i-t-1)],ns[j]+a[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)
		chmax(ans,max(f[i][j],g[i][j]));
	printf("%d",ans);
}