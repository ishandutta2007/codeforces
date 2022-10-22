#include<bits/stdc++.h>
using namespace std;
int T,n,p[1000005],q[1000005];
int f[1000005][2][2],g[1000005][2][2];
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=n+1;
	f[1][0][0]=f[1][1][0]=-n-1;
	for(int i=1;i<n;i++)for(int j=0;j<2;j++)
		for(int k=0;k<2;k++)if(f[i][j][k]<=n){
			int x=j?p[i]:-p[i],y=f[i][j][k];
			if(k)swap(x,y);
			for(int l=0;l<2;l++){
				int z=l?p[i+1]:-p[i+1];
				if(z<y)continue;
				if(z<x){
					if(f[i+1][l][1]>x){
						f[i+1][l][1]=x;
						g[i+1][l][1]=j<<1|k;
					}
				}else{
					if(f[i+1][l][0]>y){
						f[i+1][l][0]=y;
						g[i+1][l][0]=j<<1|k;
					}
				}
			}
		}
	int t1=-1,t2=-1;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)
		if(f[n][i][j]<=n)t1=i,t2=j;
	if(t1<0){
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=n;i;i--){
		q[i]=t1?p[i]:-p[i];
		if(i==1)break;
		int msk=g[i][t1][t2];
		t1=msk>>1,t2=msk&1;
	}
	for(int i=1;i<=n;i++)printf("%d ",q[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}