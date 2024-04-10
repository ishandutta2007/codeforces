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
const int o=1e3+10;
int T,n,m,a[o][o],b[o][o];bool flg;
int main(){
	read(T);while(T--){
		read(m);read(n);flg=0;
		for(int i=0;i<=m+1;++i) for(int j=0;j<=n+1;++j) b[i][j]=0;
		for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) read(a[i][j]),++b[i][j];
		for(int i=1;i<=m&&!flg;++i) for(int j=1;j<=n;++j) if(a[i][j]>b[i-1][j]+b[i+1][j]+b[i][j-1]+b[i][j+1]){printf("NO\n");flg=1;break;}
		if(flg) continue;printf("YES\n");
		for(int i=1;i<=m;++i){for(int j=1;j<=n;++j) write(b[i-1][j]+b[i+1][j]+b[i][j-1]+b[i][j+1]),putchar(' ');putchar('\n');}
	}
	return 0;
}