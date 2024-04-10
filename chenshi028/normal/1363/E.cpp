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
const int o=2e5+10;
#define int long long
int min(int a,int b){return a<b?a:b;}
int n,s[2][o],a[o],b[o],c[o],U,V,cnt,h[o],ans;
struct Edge{int v,p;}e[o<<1];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa){
	if(b[nw]^c[nw]) ++s[b[nw]][nw];
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) a[e[i].v]=min(a[e[i].v],a[nw]),dfs(e[i].v,nw),s[0][nw]+=s[0][e[i].v],s[1][nw]+=s[1][e[i].v];
	if(s[0][nw]>=s[1][nw]) s[0][nw]-=s[1][nw],ans+=a[nw]*s[1][nw]*2,s[1][nw]=0;
	else s[1][nw]-=s[0][nw],ans+=a[nw]*s[0][nw]*2,s[0][nw]=0; 
}
signed main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),read(b[i]),read(c[i]);
	for(int i=1;i<n;++i) read(U),read(V),ad(U,V),ad(V,U);
	dfs(1,0);
	if(s[1][1]||s[0][1]) printf("-1");
	else write(ans); 
	return 0;
}