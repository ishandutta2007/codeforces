#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
const int o=100000;
inline int min(int a,int b){return a<b?a:b;}
#define write(a) printf("%d",a)
int T,n,a[o],ans,mn;
int main(){
	for(read(T);T--;){
		read(n);ans=n;mn=o;for(int i=1;i<=n;++i) read(a[i]),mn=min(a[i],mn);
		for(int i=1;i<=n;++i) ans-=(a[i]==mn);write(ans);putchar('\n');
	}
	return 0;
}