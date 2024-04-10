#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 13
#define maxm 105
using namespace std;

int T,n,m,i,j,k,a[maxn][maxm],b[maxn][maxn];
struct arr{
	int mx,i;
} p[maxn];
int cmp(arr a,arr b){return a.mx>b.mx;}
int f[maxn][1<<maxn],g[maxn][1<<maxn],s[1<<maxn];
int len[1<<maxn],_3[maxn];

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&T);
	for(i=0;i<maxn;i++) len[1<<i]=i;
	_3[0]=1; for(i=1;i<maxn;i++) _3[i]=_3[i-1]*3;
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) 
			scanf("%d",&a[i][j]);
		for(i=1;i<=m;i++){
			p[i].mx=0;
			for(j=1;j<=n;j++) p[i].mx=max(p[i].mx,a[j][i]);
			p[i].i=i;
		}
		sort(p+1,p+1+m,cmp);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(i=1;i<=min(n,m);i++){
			k=p[i].i;
			memset(s,0,sizeof(s));
			for(int S=1;S<1<<n;S++) s[S]=s[S-(S&-S)]+a[len[S&-S]+1][k];
 			for(int S=0;S<1<<n;S++) for(j=0;j<n;j++){
				int T=(S>>j)+((S&((1<<j)-1))<<(n-j));
				g[i][T]=max(g[i][T],s[S]);
			}
		}
		for(int Q=0;Q<_3[n];Q++){
			int S=0,T=0;
			for(i=0;i<n;i++){
				k=Q%_3[i+1]/_3[i];
				if (k==2) S+=1<<i;
				if (k==1) T+=1<<i;
			}
			for(i=1;i<=n;i++) f[i][S+T]=max(f[i][S+T],f[i-1][S]+g[i][T]);
		}
		printf("%d\n",f[n][(1<<n)-1]);
	}
}