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
const int o=1e3+10;
int T,n,a[o],x,y;
inline short c1(int p,int q,int r){return (p>=q)+(q>=r);}
inline short c2(int p,int q,int r){return (p<=q)+(q<=r);}
int main(){
	read(T);while(T--){
		read(n);x=y=0;
		for(int i=1;i<=n;++i) read(a[i]),a[i]=a[i]<0?-a[i]:a[i];
		for(int i=2;i<=n;++i) if(a[i]>a[i-1]) ++x;else if(a[i]<a[i-1]) ++y;else ++x,++y;
		if(y<n/2)
			for(int i=2;i<n&&y<n/2;++i)
				if(c1(a[i-1],-a[i],a[i+1])>c1(a[i-1],a[i],a[i+1])) y+=c1(a[i-1],-a[i],a[i+1])-c1(a[i-1],a[i],a[i+1]),a[i]=-a[i];
		if(x<n/2)
			for(int i=2;i<n&&x<n/2;++i)
				if(c2(a[i-1],-a[i],a[i+1])>c2(a[i-1],a[i],a[i+1])) x+=c2(a[i-1],-a[i],a[i+1])-c2(a[i-1],a[i],a[i+1]),a[i]=-a[i];
		for(int i=1;i<=n;++i) write(a[i]),putchar(' ');putchar('\n');
	}
	return 0;
}