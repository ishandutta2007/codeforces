#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[111],mex[111][111],f[111][111],vis[111];
void solve(){
	int n,i,j,k;
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n){
		memset(vis,0,sizeof(vis));
		for(j=i;j<=n;j++){
			if(a[j]<=n) vis[a[j]]=1;
			mex[i][j]=0;
			while(vis[mex[i][j]]) mex[i][j]++;
			f[i][j]=mex[i][j]+1;
		}
	}
	int ans=0;
	for(i=n;i;i--){
		for(j=i;j<=n;j++){
			for(k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+mex[k+1][j]+1);
			}
			ans+=f[i][j];
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}