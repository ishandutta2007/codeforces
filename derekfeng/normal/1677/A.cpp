#include<bits/stdc++.h>
using namespace std;
int a[5003],f[5003][5003];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=0;i<=n+1;i++)
			memset(f[i],0,sizeof(f[i]));
		for(int i=1;i<=n;i++){
			memcpy(f[i],f[i-1],sizeof(f[i]));
			int t=0;
			for(int j=1;j<=n;j++){
				t|=(a[j]==i);
				f[i][j]+=t;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			int b=a[i],c=a[j];
			int p1=f[c-1][i-1],p2=f[b-1][n]-f[b-1][j];
			ans+=p1*p2;
		}
		printf("%lld\n",ans);
	}
}