#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
inline int max(int a,int b){return a>b?a:b;}
const int o=1e5+10;
int n,a[o],b[o],c[o],l,cnt;
int main(){
	read(n);for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) l=max(l,b[i]=(a[i]>a[i-1]?b[i-1]+1:1));
	for(int i=n;i;--i) l=max(l,c[i]=(a[i]>a[i+1]?c[i+1]+1:1));
	for(int i=1;i<=n;++i) cnt+=(l==b[i])+(l==c[i]);
	if(cnt==2&&(l&1)) for(int i=1;i<=n;++i) if(l==b[i]&&l==c[i]){putchar('1');return 0;}
	putchar('0');
	return 0;
}