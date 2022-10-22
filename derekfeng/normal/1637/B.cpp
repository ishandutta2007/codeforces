#include<bits/stdc++.h>
using namespace std;
int t,n,a[103],mex[103][103],f[103];
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
		bool f[203];memset(f,0,sizeof(f));
		for(int k=i;k<=j;k++)if(a[i]<=200)f[a[i]]=1;
		int g=0;
		while(f[g])g++;
		mex[i][j]=g;
	}
	int ans=0;
	for(int l=1;l<=n;l++)for(int r=l;r<=n;r++){
		memset(f,0,sizeof(f));
		f[l-1]=0;
		for(int j=l;j<=r;j++)for(int i=l;i<=j;i++)
			f[j]=max(f[j],f[i-1]+mex[i][j]+1);
		ans+=f[r];
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}