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
const int o=1e5+10;
int T,n,a[o];
inline void slv(){
	read(n);for(int i=1;i<=n;++i) read(a[i]);
	if(n>2&&a[1]+a[2]<=a[n]){printf("1 2 ");write(n);putchar('\n');return;}
	printf("-1\n");
}
int main(){read(T);while(T--) slv();return 0;}