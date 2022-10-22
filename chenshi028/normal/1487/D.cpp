#include<cstdio>
#include<cmath>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n;
inline int Max(int a,int b){return a>b?a:b;}
int main(){
	for(read(T);T--;) read(n),write(Max(((int)(sqrt(2*n-1))-1)/2,0)),putchar('\n');
	return 0;
}