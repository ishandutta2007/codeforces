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
const int o=1e4+10;
int T,n,a[o],gs[o],tk[o],tp,t;
inline bool ed(){for(int i=1;i<=n;++i) if(a[i]<a[i-1]) return false;return true;}
inline int mex(){for(int i=0;i<=n;++i) gs[i]=0;for(int i=1;i<=n;++i) ++gs[a[i]];for(int i=0;i<=n;++i) if(!gs[i]) return i;}
int main(){
	read(T);while(T--){
		read(n);for(int i=1;i<=n;++i) read(a[i]);tp=0;
		while(!ed()){
			t=mex();
			if(t==n){for(int i=1;i<=n;++i) if(a[i]^(i-1)){a[tk[++tp]=i]=t;break;}}
			else a[tk[++tp]=t+1]=t;
		}
		write(tp);putchar('\n');for(int i=1;i<=tp;++i) write(tk[i]),putchar(' ');putchar('\n');
	}
	return 0;
}