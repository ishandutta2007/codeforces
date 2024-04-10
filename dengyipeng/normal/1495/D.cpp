#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 405
#define ll long long
#define mo 998244353
using namespace std;

int n,m,i,j,k,a[maxn][maxn];
int f[maxn][maxn],c0[maxn],c1[maxn],g[maxn][maxn];

int main(){
	scanf("%d%d",&n,&m);
	memset(f,127,sizeof(f));
	for(i=1;i<=m;i++) {
		scanf("%d%d",&j,&k),f[j][k]=f[k][j]=1;
		a[j][++a[j][0]]=k;
		a[k][++a[k][0]]=j;
	}
	for(i=1;i<=n;i++) f[i][i]=0;
	for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++)
		if (f[i][k]<=n&&f[k][j]<=n)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int S=1;S<=n;S++,printf("\n")) for(int T=1;T<=n;T++){
		int cnt=0;
		for(i=1;i<=n;i++) if (f[S][i]+f[i][T]==f[S][T])
			cnt++;
		ll ans=0;
		if (cnt==f[S][T]+1){
			c0[0]=c1[0]=1;
			ans=1;
			for(int x=1;x<=n;x++){
				if (x==S||x==T) continue;
				if (f[S][x]+f[S][T]==f[x][T]&&f[S][x]>1){
					int c=0;
					for(i=1;i<=a[x][0];i++){
						int y=a[x][i];
						if (f[S][y]+f[S][T]==f[y][T]&&f[S][x]-1==f[S][y])
							c++;
					}
					ans=ans*c%mo;
				} else 
				if (f[T][x]+f[S][T]==f[S][x]&&f[T][x]>1){
					int c=0;
					for(i=1;i<=a[x][0];i++){
						int y=a[x][i];
						if (f[T][y]+f[S][T]==f[y][S]&&f[T][x]-1==f[T][y])
							c++;
					}
					ans=ans*c%mo;
				} else 
				if (f[S][x]+f[x][T]!=f[S][T]){
					int c=0;
					for(i=1;i<=a[x][0];i++){
						int y=a[x][i];
						if (f[S][x]==f[S][y]+1&&f[T][x]==f[T][y]+1)
							c++;
					}
					ans=ans*c%mo;					
				}
			}
		}
		printf("%lld ",ans);
	}
}