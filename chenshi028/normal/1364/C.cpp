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
const int o=1e6+10;
int n,a[o],b[o],c[o],hd,tl,tmp;
int main(){
	read(n);for(int i=1;i<=n;++i) read(a[i]);tmp=a[n];
	for(int i=n;i;--i)
		if(a[i]^a[i-1]){b[i]=a[i-1];for(int j=a[i-1]+1;j<a[i];++j) c[++tl]=j;}
		else b[i]=hd<tl?c[++hd]:++tmp;
	if(hd<tl){write(-1);return 0;}
	for(int i=1;i<=n;++i) write(b[i]),putchar(' ');
	return 0;
}