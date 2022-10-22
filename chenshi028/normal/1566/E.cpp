#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=4e5+10;
int T,n,h[o],cnt;bool lv[o],buf[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	lv[nw]=buf[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		dfs(e[i].v,nw),lv[nw]&=(buf[e[i].v]&&!lv[e[i].v]),buf[nw]&=lv[e[i].v]|buf[e[i].v];
	if(lv[nw]) ++cnt;
	if(nw!=1&&buf[nw]&&!lv[nw]) --cnt;
}
int main(){
	for(read(T);T--;printf("%d\n",cnt)){
		read(n);cnt=0;
		for(int i=1;i<=n;++i) h[i]=0;
		for(int i=1,j,k;i<n;++i) read(j),read(k),ad(j,k),ad(k,j);
		dfs(1,cnt=0);
	}
	return 0;
}