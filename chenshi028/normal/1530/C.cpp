#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%lld",a)
const int o=1e5+10;
#define int long long
int T,n,a[o],b[o],s[o],s2[o],l,r,md;
inline int sa(int x){if(x<=n) return s[x];return s[n]+(x-n)*100;}
inline int sb(int x,int ad){if(x<=ad) return 0;return s2[x-ad];}
signed main(){
	for(read(T);T--;putchar('\n')){
		read(n);
		for(int i=1;i<=n;++i) read(a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;++i) read(b[i]);
		sort(b+1,b+1+n);
		for(int i=1;i<=n;++i) s2[i]=s2[i-1]+b[i];
		l=0;r=1e9;
		while(l<r){md=l+r>>1;if(md*100+s[n]-sa((md+n)/4)>=s2[n]-sb((n+md)/4,md)) r=md;else l=md+1;}
		write(l);
	}
	return 0;
}