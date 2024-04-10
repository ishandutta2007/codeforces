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
inline int max(int a,int b){return a>b?a:b;}
const int o=1e5+10;
int T,n,mx,x,s[o];
#define f for(int i=1;i<=n;++i)
int main(){
	read(T);while(T--){read(n);mx=0;f s[i]=0;f read(x),++s[x],mx=max(mx,s[x]);x=0;f if(s[i]==mx) ++x;write((n-mx*x)/(mx-1)+x-1);putchar('\n');}
	return 0;
}