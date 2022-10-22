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
int t,n,p[o],k,q[o];
inline bool gs(int a,int b){return a>b;}
int main(){
	read(t);while(t--){
		read(n);
		for(int i=1;i<=n;++i) read(p[i]);
		q[k=1]=p[1];for(int i=2;i<n;++i) if(gs(p[i-1],p[i])^gs(p[i],p[i+1])) q[++k]=p[i];q[++k]=p[n];
		write(k);putchar('\n');
		for(int i=1;i<=k;++i) write(q[i]),putchar(' ');
		putchar('\n');
	}
	return 0;
}