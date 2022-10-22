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
int t,n,a[o],ans;
int main(){
	read(t);while(t--){
		read(n);ans=0;for(int i=1;i<=n;++i){read(a[i]);ans+=((a[i]^i)&&a[i-1]==i-1);}
		write(ans>2?2:ans);putchar('\n'); 
	}
	return 0;
}