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
const int o=2e5+10;
int T,n,b[o];long long ans;
int main(){
	read(T);while(T--){read(n);ans=0;for(int i=1;i<=n;++i) read(b[i]);for(int i=2;i<=n;++i) if(b[i]<b[i-1]) ans+=b[i-1]-b[i];write(ans);putchar('\n');}
	return 0;
}