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
const int o=2e6+10;
int T,n,a[o],f[o],s[o];long long ans;char x[o];
int main(){
	read(T);while(T--){
		read(n);scanf("%s",x+1);for(int i=1;i<=n;++i) s[i]=s[i-1]+(a[i]=x[i]-48);ans=0;
		for(int i=0;i<=18*n;++i) f[i]=0;
		for(int i=n;i;--i) ++f[s[i]-i+9*n],ans+=f[s[i-1]-i+1+9*n];
		write(ans);putchar('\n');
	}
	return 0;
}