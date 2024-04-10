#include<cstdio>
#include<vector>
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
int T,n,m,f[o],d[o],h[o],cnt,U,V;bool vis[o];vector<int> nod[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){nod[d[nw]].push_back(nw);for(int i=h[nw];i;i=e[i].p) if(!vis[e[i].v]) vis[e[i].v]=1,d[e[i].v]=d[f[e[i].v]=nw]+1,dfs(e[i].v);}
int main(){
	read(T);while(T--){
		read(n);read(m);for(int i=1;i<=n;++i) vis[i]=h[i]=0,nod[i].clear();cnt=0;
		for(int i=1;i<=m;++i) read(U),read(V),ad(U,V),ad(V,U);
		dfs(vis[1]=d[1]=1);
		if(nod[n+1>>1].size())
			{printf("PATH\n");write(n+1>>1);putchar('\n');for(int i=nod[n+1>>1][0];i;i=f[i]) write(i),putchar(' ');putchar('\n');continue;}
		printf("PAIRING\n");write(cnt=(n+3)/4);putchar('\n');
		for(int i=1;i<=n&&cnt;++i) for(int j=1;j<nod[i].size()&&cnt;j+=2) write(nod[i][j-1]),putchar(' '),write(nod[i][j]),putchar('\n'),--cnt;
	}
	return 0;
}