#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[3005],f[3005][3005];
int b[3005][22],sum[3005];
bool vis[3005][3005];
int DFS(int l,int r){
	if(vis[l][r])return f[l][r];
	vis[l][r]=1;
	if(l==r)return f[l][r]=1;
	if(a[l]==a[l+1])return f[l][r]=DFS(l+1,r);
	if(a[r]==a[r-1])return f[l][r]=DFS(l,r-1);
	f[l][r]=1+min(DFS(l+1,r),DFS(l,r-1));
	int i;
	for(i=1;i<=sum[a[l]];++i){
		int id=b[a[l]][i];
		if(id>l&&id<=r){
			f[l][r]=min(f[l][r],DFS(l+1,id-1)+DFS(id,r));
		}
	}
	return f[l][r];
}
int main(){
	int T,n,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sum[a[i]]=0;
			for(j=1;j<=n;++j)vis[i][j]=0;
		}
		for(i=1;i<=n;++i){
			b[a[i]][++sum[a[i]]]=i;
		}
		printf("%d\n",DFS(1,n)-1);
	}
	return 0;
}