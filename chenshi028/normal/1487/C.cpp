#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n;
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);
		if(n&1) for(int i=1;i<n;++i) for(int j=i+1;j<=n;++j) write(2*(j-i<=n/2)-1),putchar(' ');
		else for(int i=1;i<n;++i) for(int j=i+1;j<=n;++j) if(j-i<=(n-2)/2) write(1),putchar(' ');else if(j-i==n/2) write(0),putchar(' ');else write(-1),putchar(' ');
	}
	return 0;
}