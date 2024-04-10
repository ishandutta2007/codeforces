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
int n,m,sx,sy;
int main(){
	read(n);read(m);read(sx);read(sy);
	write(sx);putchar(' ');write(sy);putchar('\n');
	for(int i=1;i<=m;++i) if(i^sy) write(sx),putchar(' '),write(i),putchar('\n');
	for(int i=1;i<=n;++i)
		if (i^sx) if((i&1)^(i<sx)) for(int j=1;j<=m;++j) write(i),putchar(' '),write(j),putchar('\n');
		else for(int j=m;j;--j) write(i),putchar(' '),write(j),putchar('\n');
	return 0;
}