#include<cstdio>
#include<algorithm>
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
const int o=210;
#define int long long
inline int max(int a,int b){return a>b?a:b;}
int R,G,B,r[o],g[o],b[o],f[o][o][o],ans;
signed main(){
	read(R);read(G);read(B);
	for(int i=1;i<=R;++i) read(r[i]);
	for(int i=1;i<=G;++i) read(g[i]);
	for(int i=1;i<=B;++i) read(b[i]);
	sort(r+1,r+1+R);sort(g+1,g+1+G);sort(b+1,b+1+B);
	for(int i=0;i<=R;++i) for(int j=0;j<=G;++j) for(int k=0;k<=B;++k){
		if(i&&j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+r[i]*g[j]);
		if(i&&k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+r[i]*b[k]);
		if(j&&k) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+g[j]*b[k]);
		ans=max(f[i][j][k],ans);
	}
	write(ans);
	return 0;
}