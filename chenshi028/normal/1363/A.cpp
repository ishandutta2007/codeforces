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
int T,n,x,a,num[2];
int main(){
	read(T);while(T--){
		read(n);read(x);num[0]=num[1]=0;
		for(int i=1;i<=n;++i) read(a),++num[a&1];
		if((x==n&&num[1]%2==0)||(!num[0]&&x%2==0)||!num[1]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}