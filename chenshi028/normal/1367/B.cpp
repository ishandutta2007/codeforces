#include<cstdio>
#include<queue>
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
int t,n,a[o],num[2];
int main(){
	read(t);while(t--){
		num[0]=num[1]=0;
		read(n);for(int i=1;i<=n;++i){read(a[i]);if((a[i]^i^1)&1) ++num[i&1];}
		if(num[0]^num[1]) printf("-1\n");
		else write(num[0]),putchar('\n');
	}
	return 0;
}