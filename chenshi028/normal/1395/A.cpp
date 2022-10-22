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
int T,r,g,b,w;
int main(){
	read(T);
	while(T--){read(r);read(g);read(b);read(w),printf(((r&1)+(g&1)+(b&1)+(w&1)<=1)?"Yes\n":r&&g&&b&&((r&1)+(g&1)+(b&1)+(w&1)>=3)?"Yes\n":"No\n");}
	return 0;
}