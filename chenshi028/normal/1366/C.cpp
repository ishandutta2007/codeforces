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
const int o=110;
int t,n,m,a[o][o],ans,num[2];
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int main(){
	read(t);while(t--){
		read(m);read(n);ans=0;
		for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) read(a[i][j]);
		for(int i=0;i<(n+m-1)/2;++i)
			{num[0]=num[1]=0;for(int j=max(1,i+2-n);j<=i+1&&j<=m;++j) ++num[a[j][i-j+2]],++num[a[m-j+1][n-i+j-1]];ans+=min(num[0],num[1]);}
		write(ans);putchar('\n'); 
	}
	return 0;
}