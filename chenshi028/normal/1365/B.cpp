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
int T,n,a[1000],b[1000];bool flg1,flg2,flg3;
int main(){
	read(T);while(T--){
		read(n);flg1=flg2=flg3=0;
		for(int i=1;i<=n;++i) read(a[i]),flg1|=(a[i]<a[i-1]);
		for(int i=1;i<=n;++i) read(b[i]),flg2|=b[i],flg3|=!b[i];
		printf((flg1&&(!flg2||!flg3))?"No\n":"Yes\n");
	}
	return 0;
}