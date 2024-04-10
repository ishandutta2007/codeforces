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
template<class T>void Exgcd(T a,T b,T&d,T&x,T&y){
	if(!b){d=a;x=1;y=0;return;}
	Exgcd(b,a%b,d,x,y);
	T t=x;x=y;y=t-a/b*y;
}
const int o=1e5+10;
#define int long long
int n,a[o],tx,ty,tmp;
signed main(){
	read(n);for(int i=1;i<=n;++i) read(a[i]);
	if(n==1){
		putchar('1');putchar(' ');putchar('1');putchar('\n');putchar('0');putchar('\n');putchar('1');putchar(' ');
		putchar('1');putchar('\n');putchar('0');putchar('\n');putchar('1');putchar(' ');putchar('1');putchar(' ');write(-a[1]);
		return 0;
	}
	putchar('1');putchar(' ');write(n-1);putchar('\n');
	Exgcd(n-1,n,tmp,tx,ty);tx*=(n-1);
	for(int i=1;i<n;++i) write((n-a[i]%n)%n*tx),putchar(' '),a[i]+=(n-a[i]%n)%n*tx;
	putchar('\n');write(n);putchar(' ');write(n);putchar('\n');write((n-a[n]%n));putchar('\n');a[n]+=(n-a[n]%n);
	putchar('1');putchar(' ');write(n);putchar('\n');for(int i=1;i<=n;++i) write(-a[i]),putchar(' ');
	return 0;
}