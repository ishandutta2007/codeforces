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
const int o=2e6+10;
int n,mxl[o],nxt0,nxt1,ans,h[o],u[o],f[o],t;char s[o];
int fr(int x){return (f[x]==x)?x:fr(f[x]);}
inline int mrg(int x,int y){
	x=fr(x);y=fr(y);
	if(h[x]>h[y]) return f[y]=x;
	if(h[x]<h[y]) return f[x]=y;
	++h[f[x]=y];return y;
}
int main(){
	read(n);scanf("%s",s+1);
	nxt0=nxt1=n+1;
	for(int i=n;i;--i) if(s[i]==48) mxl[i]=nxt1-i,nxt0=i;else if(s[i]==49) mxl[i]=nxt0-i,nxt1=i;else mxl[i]=mxl[i+1]+1;
	for(int i=0;i<=n;++i) f[i]=u[i]=i,h[i]=1;
	for(int i=1;i<=n;++i)
	{ans=0;for(int j=u[1];j<=n&&j;j=u[fr(j)]) if(mxl[j]>=i){++ans;j+=i;continue;}else t=u[fr(j+1)],u[mrg(j,j+1)]=t;write(ans);putchar(' ');}
	return 0;
}