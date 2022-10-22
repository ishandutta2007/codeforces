#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n,m;
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);read(m);
		for(int i=1,j=1;i<=m;++i,j^=1) putchar(48+j);putchar('\n');
		for(int i=1;i<=m;++i) putchar('0');putchar('\n');
		for(int i=3;i<n-1;++i,putchar('\n')){
			if(i&1) putchar('1');else putchar('0');
			for(int j=2;j<m;++j) putchar('0');
			if(i&1) putchar('1');else putchar('0');
		}
		if(n>3){for(int i=1;i<=m;++i) putchar('0');putchar('\n');}
		for(int i=1,j=1;i<=m;++i,j^=1) putchar(48+j);
	}
	return 0;
}