#include<cstdio>
#include<cmath>
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
int t,n;bool f;
int main(){
	read(t);while(t--){
		read(n);
		if(n&1){
			f=1;for(int i=3;i*i<=n;++i) if(n%i==0){write(n/i);putchar(' ');write(n-n/i);putchar('\n');f=0;break;}
			if(f) write(1),putchar(' '),write(n-1),putchar('\n');
		}
		else write(n/2),putchar(' '),write(n/2),putchar('\n');
	}
	return 0;
}