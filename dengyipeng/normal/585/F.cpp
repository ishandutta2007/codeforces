#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1005
#define maxm 51
#define maxt 50005
#define ll long long 
#define mo 1000000007
using namespace std;

int n,d,s[maxn],a[maxm],b[maxm],i,j,k;
int tot,t[maxt][10],rt,bz[maxt],fa[maxt];
ll f[2][maxt][2][2][2];

void bfs(){
	static int d[maxt];
	int h=0,w=1; d[1]=rt;
	while (h<w){
		int x=d[++h];
		for(int i=0;i<10;i++) if (t[x][i]){
			int y=t[x][i];
			if (x==rt) fa[y]=rt; else {
				fa[y]=fa[x];
				while (fa[y]!=rt&&!t[fa[y]][i]) fa[y]=fa[fa[y]];
				if (t[fa[y]][i]) fa[y]=t[fa[y]][i];
			}
			d[++w]=y;
		} else t[x][i]=t[fa[x]][i];
	}
}

void dp(){
	int p,q;f[0][rt][1][1][0]=1;
	for(i=0;i<d;i++) {
		p=i&1^1,q=i&1,memset(f[p],0,sizeof(f[p]));
		for(int x=1;x<=tot;x++) for(int p1=0;p1<2;p1++) for(int p2=0;p2<2;p2++) for(k=0;k<2;k++) if (f[q][x][p1][p2][k])
			for(j=0;j<10;j++) if ((p1==0||j>=a[i+1])&&(p2==0||j<=b[i+1])){
				int y=(t[x][j])?t[x][j]:rt;
				(f[p][y][p1&&j==a[i+1]][p2&&j==b[i+1]][k|bz[y]]+=f[q][x][p1][p2][k])%=mo;
			}
	}
	ll ans=0;
	for(i=1;i<=tot;i++) for(j=0;j<2;j++) for(k=0;k<2;k++)
		(ans+=f[d&1][i][j][k][1])%=mo;
	printf("%lld",ans);
}

int main(){
	char ch=getchar();
	while (ch>='0'&&ch<='9') s[++n]=ch-'0',ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') a[++a[0]]=ch-'0',ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') b[++b[0]]=ch-'0',ch=getchar();
	d=a[0];
	if (n<d/2) printf("0"),exit(0);
	
	rt=tot=1;
	for(i=1;i+d/2-1<=n;i++) {
		int x=rt;
		for(j=0;j<d/2;j++) {
			if (!t[x][s[i+j]]) t[x][s[i+j]]=++tot;
			x=t[x][s[i+j]];
		}
		bz[x]=1;
	}
	bfs();
	dp();
}