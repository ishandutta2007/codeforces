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
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int t,n,x,m,mnl,mxr,l,r;
int main(){
	read(t);while(t--){
		read(n);read(x);read(m);mnl=mxr=x;
		for(int i=1;i<=m;++i){read(l);read(r);if(l<=mxr&&r>=mnl) mxr=max(mxr,r),mnl=min(mnl,l);}
		write(mxr-mnl+1);putchar('\n');
	}
	return 0;
}