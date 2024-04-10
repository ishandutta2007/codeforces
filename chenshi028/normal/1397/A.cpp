#include<cstdio>
#include<cstring>
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
const int o=1010;
int T,n,c[30];char s[o];
inline void slv(){
	read(n);for(int i=1;i<30;++i) c[i]=0;
	for(int j=1;j<=n;++j){scanf("%s",s+1);for(int i=1;i<=strlen(s+1);++i) ++c[s[i]-96];}
	for(int i=1;i<30;++i) if(c[i]%n){printf("NO\n");return;}
	printf("YES\n");
}
int main(){read(T);while(T--) slv();return 0;}