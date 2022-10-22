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
const int o=4e5+10;
int n,a[o],b[o],c[o],d[o],ans[o],res;
inline int max(int a,int b){return a>b?a:b;}
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),c[a[i]]=i;
	for(int i=1;i<=n;++i) read(b[i]),d[b[i]]=i;
	for(int i=1;i<=n;++i) res=max(res,++ans[(c[i]-d[i]+n-1)%n+1]);
	write(res);
	return 0;
}