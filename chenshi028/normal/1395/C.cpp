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
const int o=210;
int n,m,a[o],b[o],ans;bool vis[o][o],phuc,tmp;
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=m;++i) read(b[i]);
	for(int i=9;i+1;--i){
		phuc=1;
		for(int j=1;j<=n;++j){tmp=0;for(int k=1;k<=m;++k) if(!vis[j][k]&&!(((a[j]&b[k])>>i)&1)) tmp=1;phuc&=tmp;}
		if(phuc){for(int j=1;j<=n;++j) for(int k=1;k<=m;++k) if(((a[j]&b[k])>>i)&1) vis[j][k]=1;}
		else ans+=(1<<i);
	}
	write(ans);
	return 0;
}