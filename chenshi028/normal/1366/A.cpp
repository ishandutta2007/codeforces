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
int t,a,b;
int main(){
	read(t);while(t--){
		read(a);read(b);
		if(a>=2*b) write(b);
		else if(b>=2*a) write(a);
		else if(a>=b) write(a-b+(2*b-a)/3*2+((2*b-a)%3==2?1:0));
		else write(b-a+(2*a-b)/3*2+((2*a-b)%3==2?1:0));
		putchar('\n');
	}
	return 0;
}