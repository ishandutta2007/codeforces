#include<cstdio>
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
inline int mn(int a,int b){return a<b?a:b;}
const int o=1e6+10;
int n,h[o],cnt,U,V,c[2];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa,bool col){++c[col];for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) dfs(e[i].v,nw,!col);}
int main(){
	read(n);
	for(int i=1;i<n;++i) read(U),read(V),ad(U,V),ad(V,U);
	dfs(1,0,0);
	write(mn(c[0],c[1])-1); 
	return 0;
}