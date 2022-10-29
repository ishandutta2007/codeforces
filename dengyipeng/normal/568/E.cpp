#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int n,m,i,j,k,a[maxn],b[maxn],c[maxn],bz[maxn];
int w,d[maxn][2],g[maxn],f[maxn][2];

void read(int &x){
	x=0; char ch=getchar(); int tp=1;
	for(;(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
	if (ch=='-') tp=-1,ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x=x*tp;
}

int main(){
	read(n);for(i=1;i<=n;i++) read(a[i]); a[n+1]=1e9+5;
	read(m);for(i=1;i<=m;i++) read(b[i]);
	sort(b+1,b+1+m);
	for(i=1;i<=n+1;i++) if (a[i]!=-1){
		int l=0,r=w,mid,id;
		while (l<=r){
			mid=(l+r)>>1;
			if (a[i]>d[mid][1]) id=mid,l=mid+1;
			else r=mid-1;
		}
		g[i]=d[id][0];
		if (id==w) w++,d[w][0]=i,d[w][1]=a[i];
		else if (a[i]<d[id+1][1]) d[id+1][0]=i,d[id+1][1]=a[i];
	} else {
		int id=0;
		for(j=1;j<=m;j++) {
			while (id<w&&d[id+1][1]<b[j]) id++;
			f[j][0]=d[id][0],f[j][1]=id;
		}
		for(j=1;j<=m;j++){
			id=f[j][1];
			if (id==w) w++,d[w][0]=f[j][0],d[w][1]=b[j];
			else if (b[j]<d[id+1][1]) d[id+1][0]=f[j][0],d[id+1][1]=b[j];
		}
	}
	int now=m; i=d[w][0];
	while (i&&now){
		j=g[i];
		while (b[now]>=a[i]&&now) now--;
		for(k=i-1;k>j&&b[now]>a[j]&&now;k--) if (a[k]==-1){
			c[k]=now,bz[now]=1,now--;
			while (now&&b[now]==b[now+1]) now--;
		}
		i=j;
	}
	k=1;
	for(i=1;i<=n;i++) if (a[i]==-1&&!c[i]){
		while (bz[k]) k++;
		c[i]=k++;
	}
	for(i=1;i<=n;i++) if (a[i]==-1) printf("%d ",b[c[i]]);
	else printf("%d ",a[i]);
}