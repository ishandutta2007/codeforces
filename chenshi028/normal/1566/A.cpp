#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
int T,n,s; 
int main(){
	for(read(T);T--;) read(n),read(s),printf("%d\n",s/((n+2)>>1));
	return 0;
}