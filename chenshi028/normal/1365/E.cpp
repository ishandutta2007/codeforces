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
int n;long long a[600],ans;
inline long long max(long long a,long long b){return a>b?a:b;}
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k) ans=max(ans,a[i]|a[j]|a[k]);
	write(ans);
	return 0;
}