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
const int o=2e5+10,inf=2e9+10;
#define int long long
inline int max(int a,int b){return a>b?a:b;}
int T,n,k,a[o],mx;
signed main(){
	read(T);while(T--){
		read(n);read(k);mx=-inf;
		for(int i=1;i<=n;++i) read(a[i]),mx=max(mx,a[i]);
		for(int i=1;i<=n;++i) a[i]=mx-a[i];
		if(k&1) for(int i=1;i<=n;++i) write(a[i]),putchar(' ');
		else{mx=-inf;for(int i=1;i<=n;++i) mx=max(mx,a[i]);for(int i=1;i<=n;++i) write(mx-a[i]),putchar(' ');}
		putchar('\n');
	}
	return 0;
}