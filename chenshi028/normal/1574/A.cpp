#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
int T,n;
int main(){
	for(read(T);T--;){
		read(n);
		for(int i=1;i<=n;++i,putchar('\n')){
			for(int j=1;j<=i;++j) putchar('(');
			for(int j=1;j<=i;++j) putchar(')');
			for(int j=1;j<=n-i;++j) printf("()");
		}
	}
	return 0;
}