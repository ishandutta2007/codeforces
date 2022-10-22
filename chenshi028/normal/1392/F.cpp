#include<cstdio>
using namespace std;
#pragma GCC optimize(3)
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
#define int long long
int n,h,s;
signed main(){
	read(n);for(int i=1;i<=n;++i) read(h),s+=h;s-=n*(n-1)/2;
	for(int i=1;i<=n;++i) write((i>n+s-(n+s-1)/n*n)?(i+(n+s-1)/n-2):(i+(n+s-1)/n-1)),putchar(' ');
	return 0;
}