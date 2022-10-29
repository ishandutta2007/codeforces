#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 1505
using namespace std;

int n,m,i,j,k,a[maxn][maxn],b[maxn][maxn],f[maxn][maxn],c;
int d[maxn],tot,rk[maxn],cnt[maxn],D[maxn],tot0,p[maxn],id[maxn];

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

int cmp(int i,int j){
	for(int k=1;k<=c;k++) if (a[i][p[k]]!=a[j][p[k]])
		return a[i][p[k]]<a[j][p[k]];
	return 0;
}

int main(){
	read(n),read(m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) read(a[i][j]);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) read(b[i][j]);
	for(j=1;j<=m;j++) for(i=1;i<=n;i++) f[i][j]=(b[i][j]>=b[i-1][j])*f[i-1][j]+1;
	d[1]=n,tot=1;
	for(i=1;i<=m;i++) cnt[i]+=f[n][i]==n;
	for(int now=m;now>=1;now--){
		k=0;
		for(i=1;i<=m;i++) if (!rk[i]&&cnt[i]==tot) k=i;
		if (!k) break;
		tot0=0,rk[k]=now,p[++c]=k;
		for(i=1;i<=tot;i++) {
			for(j=d[i-1]+2;j<=d[i];j++) if (b[j][k]!=b[j-1][k]) break;
			if (j<=d[i]){
				for(int t=1;t<=m;t++) if (!rk[t])
					cnt[t]-=f[d[i]][t]>=d[i]-d[i-1];
				int pre=d[i-1]; j=d[i-1]+1;
				while (j<=d[i]){
					while (j<d[i]&&b[j][k]==b[j+1][k]) j++;
					D[++tot0]=j;
					for(int t=1;t<=m;t++) if (!rk[t])
						cnt[t]+=f[j][t]>=j-pre;
					pre=j,j++;
				}
			} else D[++tot0]=d[i];
		}
		tot=tot0,memcpy(d,D,sizeof(d));
	}
	for(i=1;i<=n;i++) id[i]=i;
	stable_sort(id+1,id+1+n,cmp);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if (b[i][j]!=a[id[i]][j])
		printf("-1\n"),exit(0);
	printf("%d\n",c);
	for(i=c;i>=1;i--) printf("%d ",p[i]);
}