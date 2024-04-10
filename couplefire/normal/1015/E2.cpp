#include<bits/stdc++.h>
using namespace std;const int N=1e3+7;typedef pair<int,pair<int,int>>pa;
int R[N][N],C[N][N],u[N][N],d[N][N],l[N][N],r[N][N],n,m,i,j,k;char a[N][N];vector<pa>e;
int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;++i)scanf("%s",a[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(a[i][j]=='.')l[i][j]=j;else l[i][j]=l[i][j-1];
	for(i=1;i<=n;++i)for(r[i][m+1]=m+1,j=m;j>=1;--j)if(a[i][j]=='.')r[i][j]=j;else r[i][j]=r[i][j+1];
	for(j=1;j<=m;++j)for(i=1;i<=n;++i)if(a[i][j]=='.')d[i][j]=i;else d[i][j]=d[i-1][j];
	for(j=1;j<=m;++j)for(i=n,u[n+1][j]=n+1;i>=1;--i)if(a[i][j]=='.')u[i][j]=i;else u[i][j]=u[i+1][j];
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(a[i][j]=='*'){
		k=min({j-l[i][j],r[i][j]-j,i-d[i][j],u[i][j]-i})-1;
		if(k){
			e.push_back({i,{j,k}});
			R[i-k][j]++;
			R[i+k+1][j]--;
			C[i][j-k]++;
			C[i][j+k+1]--;
		}
	}
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)R[i][j]+=R[i-1][j],C[i][j]+=C[i][j-1];
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(a[i][j]=='*'&&!R[i][j]&&!C[i][j])return 0*puts("-1");
	printf("%d\n",int(e.size()));for(auto&x:e)printf("%d %d %d\n",x.first,x.second.first,x.second.second);
}