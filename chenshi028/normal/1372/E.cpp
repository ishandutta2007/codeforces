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
inline int max(int a,int b){return a>b?a:b;}
const int o=110;
int n,m,k,l,r,q,lft[o][o],rgt[o][o],f[o][o];
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i){
		read(k);
		for(int j=1;j<=k;++j){
			read(l);read(r);
			for(int p=l;p<=r;++p) lft[i][p]=l,rgt[i][p]=r;
		}
	}
	for(int i=m;i;--i)
		for(int j=i;j<=m;++j)
			for(int K=i;K<=j;++K){
				q=0;
				for(int p=1;p<=n;++p) q+=(lft[p][K]>=i&&rgt[p][K]<=j);
				f[i][j]=max(f[i][j],f[i][K-1]+f[K+1][j]+q*q);
			}
	write(f[1][m]);
	return 0;
}