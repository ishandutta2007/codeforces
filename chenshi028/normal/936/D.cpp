#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e6+10,inf=1e9+10;
int n,a,b,t,cnt,m=-1,tot,x[o],y[o],z[o],f[o][2],xm[o],ym[o],xa[o],ya[o],lst[o][2];bool p[o][2];
void dfs(int x,int y){
	if(!x&&!y) return;
	if(lst[x][y]==x) xm[++cnt]=z[x],ym[cnt]=!y,dfs(x,!y);
	else{if(p[x][y]) xa[++tot]=z[lst[x][y]]+t-f[lst[x][y]][y],ya[tot]=y;dfs(x-1,y);}
}
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&t);z[cnt=1]=n+1;
	for(int i=1;i<=a;++i) scanf("%d",&x[i]),z[++cnt]=x[i],z[++cnt]=x[i]+1;
	for(int i=1;i<=b;++i) scanf("%d",&y[i]),z[++cnt]=y[i],z[++cnt]=y[i]+1;
	sort(z,z+cnt+1);
	for(int i=0;i<=cnt;++i) if(!i||z[i]-z[i-1]) z[++m]=z[i];
	for(int i=1;i<=m;++i) f[i][0]=f[i][1]=-inf;
	for(int i=1,j=0;i<=a;p[j][0]=1,++i) for(;z[j]<x[i];++j);
	for(int i=1,j=0;i<=b;p[j][1]=1,++i) for(;z[j]<y[i];++j);
	for(int i=0;i<m;++i) for(int $=0;$<2;++$){
		if(f[i][$]<min(t,f[i][!$])&&!p[i][$]) f[i][$]=min(t,f[i][!$]),lst[i][$]=i;
		if(f[i][$]<0) continue;
		if(f[i][$]+z[i+1]-z[i]>t*p[i+1][$]) f[i+1][$]=f[i][$]+z[i+1]-z[i]-t*p[i+1][$],lst[i+1][$]=i;
	}
	if(f[m][0]>0){
		printf("Yes\n");
		dfs(m,cnt=0);
		printf("%d\n",cnt);
		for(int i=cnt;i;--i) printf("%d ",xm[i]);
		printf("\n%d\n",tot);
		for(int i=tot;i;--i) printf("%d %d\n",xa[i],ya[i]+1);
		return 0;
	}
	if(f[m][1]>0){
		printf("Yes\n");
		cnt=0;dfs(m,1);
		printf("%d\n",cnt);
		for(int i=cnt;i;--i) printf("%d ",xm[i]);
		printf("\n%d\n",tot);
		for(int i=tot;i;--i) printf("%d %d\n",xa[i],ya[i]+1);
		return 0;
	}
	printf("No\n");
	return 0;
}