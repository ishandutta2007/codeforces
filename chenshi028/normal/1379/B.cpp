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
#define int long long
int t,l,r,m;
signed main(){
	read(t);while(t--){
		read(l);read(r);read(m);
		for(int i=l;i<=r;++i) if(m%i<r-l+1&&m>=i){write(i);putchar(' ');write(l+m%i);putchar(' ');write(l);putchar('\n');break;}
		else if(((i-m)%i+i)%i<r-l+1){write(i);putchar(' ');write(l);putchar(' ');write(l+((i-m)%i+i)%i);putchar('\n');break;}
	}
	return 0;
}