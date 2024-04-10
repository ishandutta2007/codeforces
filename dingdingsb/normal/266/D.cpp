#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=210,M=N*N/2;
const int inf=0x3f3f3f3f;
int n,m,u[M],v[M],w[M],ans=inf;
int f[N][N];
signed main(){
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		w[i]<<=1;
		f[u[i]][v[i]]=f[v[i]][u[i]]=min(f[v[i]][u[i]],w[i]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=m;i++){
		int x=u[i],y=v[i],r=0;
		static vector<pair<int,int> > a;a.clear();
		for(int j=1;j<=n;j++)
			a.pb(mp(f[x][j],j));
		sort(a.begin(),a.end());reverse(a.begin(),a.end());
		for(auto [val,id]:a){
			int l=f[x][id],mid=(l+r+w[i])/2;
			if(mid>=l&&mid<=l+w[i])ans=min(ans,mid);
			r=max(r,f[y][id]);
		}
	}
	printf("%.1lf",ans/2.0);
	return 0;
	printf("SJY AK IOI!!!");
}