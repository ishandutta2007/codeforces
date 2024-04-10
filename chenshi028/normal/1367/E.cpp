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
int t,n,k,u[30],g,ans;char e[o];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	read(t);while(t--){
		read(n);read(k);
		for(int i=1;i<27;++i) u[i]=0;
		scanf("%s",e+1);
		for(int i=1;i<=n;++i) ++u[e[i]-96];
		for(int i=n;i;--i){
			g=gcd(i,k);ans=0;for(int j=1;j<27;++j) ans+=(u[j]/(i/g));
			if(ans>=g){write(i);putchar('\n');break;}
		}
	}
	return 0;
}