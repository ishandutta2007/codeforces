#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long 
#define maxn 52
using namespace std;

int n,m,i,j,k,pre[maxn];
ll a[maxn],b[maxn],c[maxn],f[maxn][maxn][maxn][4][4];
void Min(ll &a,ll b){a=(a<b)?a:b;}

int V(int i,int p){
	if (p==0) return a[i]>>k&1;
	if (p==1) return a[i]>>k&1^1;
	if (p==2) return b[i]>>k&1;
	if (p==3) return b[i]>>k&1^1;
}

ll cost(int l,int r,int p,int q){
	if (l==0||r==n+1) return 0;
	int x=V(l,p),y=V(r,q);
	return c[k]*(x!=y);
}

int main(){
	scanf("%d%d",&n,&m),pre[0]=pre[n+1]=-1;
	for(i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i],&b[i]),pre[i]=-1;
		for(j=m-1;j>=0;j--) if ((a[i]>>j)<(b[i]>>j)){
			pre[i]=j;
			break;
		}
	}
	for(i=0;i<m;i++) scanf("%lld",&c[i]);
	memset(f,127,sizeof(f));
	for(i=0;i<=n;i++) for(j=0;j<=2;j+=2) for(k=0;k<=2;k+=2)
		f[m][i][i+1][j][k]=0;
	for(k=m-1;k>=0;k--){
		for(i=0;i<=n;i++) for(j=i+1;j<=n+1;j++) for(int p=0;p<=2;p+=2) for(int q=0;q<=2;q+=2)
			if (f[k+1][i][j][p][q]<1e18){
				for(int p0=0;p0<2;p0++) if (!p0||k<pre[i]){
					if (p0&&p==0&&(a[i]>>k&1)) continue;
					if (p0&&p==2&&(b[i]>>k&1^1)) continue;
					for(int q0=0;q0<2;q0++) if (!q0||k<pre[j]){
						if (q0&&q==0&&(a[j]>>k&1)) continue;
						if (q0&&q==2&&(b[j]>>k&1^1)) continue;
						Min(f[k][i][j][p+p0][q+q0],f[k+1][i][j][p][q]+cost(i,j,p+p0,q+q0));
					}
				}
			}
		for(int len=2;len<=n+1;len++) for(i=0;i+len<=n+1;i++){
			j=i+len;
			if (k)
				for(int mid=i+1;mid<j;mid++) for(int p=0;p<4;p++) for(int q=0;q<4;q++)	
					for(int t=1;t<=3;t+=2){
						if (f[k][i][mid][p][t]<1e18&&f[k][mid][j][t][q]<1e18)
							Min(f[k][i][j][p][q],f[k][i][mid][p][t]+f[k][mid][j][t][q]);
					}
			else {
				i=i;
				for(int mid=i+1;mid<j;mid++) for(int p=0;p<4;p++) for(int q=0;q<4;q++)	
					for(int t=0;t<4;t++){
						if (f[k][i][mid][p][t]<1e18&&f[k][mid][j][t][q]<1e18)
							Min(f[k][i][j][p][q],f[k][i][mid][p][t]+f[k][mid][j][t][q]);
					}
			}
		}
	}
	ll ans=1e18;
	for(i=0;i<4;i++) for(j=0;j<4;j++)
		ans=min(ans,f[0][0][n+1][i][j]);
	printf("%lld\n",ans);
}