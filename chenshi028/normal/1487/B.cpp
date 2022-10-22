#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n,k;
int main(){
	for(read(T);T--;){
		read(n);read(k);
		if(n&1) write((k-1+(k-1)/((n-1)>>1))%n+1);
		else write((k-1)%n+1);putchar('\n');
	}
	return 0;
}