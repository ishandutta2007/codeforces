//There are n pairs of pearls. We can place the n pairs in any order we want, and in each pair, we can place the two pearls in any order we want
//so that the least beauty between the right pearl of a left pair and the left pearl of the corresponding right pair is the largest
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f; 
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=2e6+10;
int n,a[o],b[o],k,h[o],cnt,d[o],ans[o],f[o],g[o],lst[o],cs;bool vis[o],flg;
struct Edge{int v,p,id;}e[o];
inline void ad(int U,int V,int ID){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].id=ID;}
void dfs(int nw){for(int i=h[nw];i;i=e[i].p) if(!vis[e[i].v]) vis[e[i].v]=1,dfs(e[i].v);}
void dfs2(int nw){
	int tmp=h[nw];
	for(int i=h[nw];i-lst[nw];i=e[i].p,++cs) if(!vis[e[i].id]){vis[e[i].id]=1;h[nw]=e[i].p;dfs2(e[i].v);if(f[e[i].id]==nw) ans[++cnt]=e[i].id*2,
	ans[++cnt]=e[i].id*2-1;else ans[++cnt]=e[i].id*2-1,ans[++cnt]=e[i].id*2;}
	lst[nw]=tmp;
}
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),read(b[i]);
	for(k=0;k<=20;++k){
		memset(h,cnt=0,sizeof h);memset(vis,0,sizeof vis);memset(d,0,sizeof d);
		for(int i=1;i<=n;++i) ad(f[i]=a[i]&((1<<k)-1),g[i]=b[i]&((1<<k)-1),i),ad(g[i],f[i],i),++d[f[i]],++d[g[i]];
		for(int i=0;i<(1<<k);++i) if(h[i]&&(d[i]&1)){flg=1;break;}
		if(flg) break;
		for(int i=0;i<(1<<k);++i) if(h[i]){dfs(i);break;}
		for(int i=0;i<(1<<k);++i) if(h[i]&&!vis[i]){flg=1;break;}
		if(flg) break;
	}
	--k;write(k);putchar('\n');
	memset(h,cnt=0,sizeof h);memset(vis,0,sizeof vis);memset(d,0,sizeof d);
	for(int i=1;i<=n;++i) ad(f[i]=a[i]&((1<<k)-1),g[i]=b[i]&((1<<k)-1),i),ad(g[i],f[i],i);
	memset(vis,cnt=0,sizeof vis);
	for(int i=0;i<(1<<k);++i) if(h[i]){dfs2(i);break;}
	for(int i=1;i<=2*n;++i) write(ans[i]),putchar(' ');
	return 0;
}