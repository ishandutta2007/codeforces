#include<cstdio>
#include<cstring>
#include<map>
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
unsigned long long t,n;map<unsigned long long,unsigned long long> m;
unsigned long long slv(unsigned long long n){
	if(n==1) return 1ull;
	if(n==2) return 3ull;
	if(m[n]) return m[n];
	unsigned long long bit,ws;
	for(bit=1,ws=0;bit<n;bit<<=1,++ws);
	if(n==bit) return m[n]=ws+1+slv(n-1);
	bit>>=1;return m[n]=slv(bit-1)+slv(n-bit)+ws;
}
int main(){read(t);while(t--){read(n);write(slv(n));putchar('\n');}return 0;}