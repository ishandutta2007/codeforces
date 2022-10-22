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
const int o=1e6+10;
int t,n,a[o],x,s,ans;bool flg;
int main(){
	read(t);while(t--){
		read(n);read(x);s=0;flg=1;
		for(int i=1;i<=n;++i) read(a[i]),s=(a[i]+s)%x,flg&=(a[i]%x==0);
		if(flg) write(-1);
		else if(s%x) write(n);
		else{for(int i=1;i<=n;++i) if(a[i]%x){ans=n-i;break;}for(int i=n;i;--i) if(a[i]%x){if(i-1>ans) ans=i-1;break;}write(ans);}
		putchar('\n');
	}
	return 0;
}