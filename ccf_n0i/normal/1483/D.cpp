#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,m,q,i,j,k,x,y,len[605][605],res[605][605],lim[605][605];
long long g[605][605],f[605];
int main(){
	scanf("%d%d",&n,&m);
	memset(len,-1,sizeof(len));
	rep(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&len[x][y]);
		len[y][x]=len[x][y];
	}
	rep(i,n)rep(j,n){
		if(i==j)g[i][j]=0;
		else if(len[i][j]!=-1) g[i][j]=len[i][j]; else g[i][j]=0x3f3f3f3f3f3f3f3fll;
	}
	memset(lim,-1,sizeof(lim));
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&lim[x][y]);
		lim[y][x]=lim[x][y];
	}
	rep(k,n)rep(i,n)rep(j,n) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	rep(i,n){
		rep(j,n) f[j]=-0x3f3f3f3f3f3f3f3fll;
		rep(j,n)if(lim[i][j]!=-1){
			rep(k,n){
				f[k]=max(f[k],((long long)lim[i][j])-g[j][k]);
			}
		}
		rep(j,n)rep(k,n)if(len[j][k]!=-1){
			if(g[i][j]+len[j][k]<=f[k]){
				res[j][k]=1;
			}
		}
	}
	int ans=0;
	rep(i,n)rep(j,i-1)if(len[i][j]!=-1&&res[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}