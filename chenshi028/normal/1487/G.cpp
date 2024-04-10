#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=405,MOD=998244353;
#define int long long
int n,f[2][o][o][3][3],c[27],g[o][o][2][2],h[o],ans;
inline void pls(int&x,int y){x+=y;if(x>MOD) x-=MOD;}
inline void sub(int&x,int y){x-=y;if(x<0) x+=MOD;}
inline int query(int x,int y){
	if(x>n||y>n) return 0;
	return (f[1][n][n][0][0]+f[1][x-1][y-1][0][0]+MOD*2-f[1][x-1][n][0][0]-f[1][n][y-1][0][0])%MOD;
}
signed main(){
	read(n);
	for(int i=1;i<27;++i) read(c[i]);
	f[1][0][0][0][0]=24*24;f[1][1][0][1][0]=f[1][1][0][0][1]=f[1][0][1][2][0]=f[1][0][1][0][2]=24;f[1][2][0][1][1]=f[1][0][2][2][2]=f[1][1][1][1][2]=f[1][1][1][2][1]=1;
	for(int i=3;i<=n;++i){
		for(int j=0;j<=i;++j) for(int k=0;j+k<=i;++k) for(int l=0;l<3;++l) for(int m=0;m<3;++m) f[0][j][k][m][l]=f[1][j][k][m][l],f[1][j][k][m][l]=0;
		for(int j=0;j<=i;++j) for(int k=0;j+k<=i;++k){
			if(j) for(int l=0;l<3;++l) pls(f[1][j][k][l][1],(f[0][j-1][k][0][l]+f[0][j-1][k][2][l])%MOD);
			if(k) for(int l=0;l<3;++l) pls(f[1][j][k][l][2],(f[0][j][k-1][0][l]+f[0][j][k-1][1][l])%MOD);
			for(int l=0;l<3;++l){for(int m=1;m<3;++m) pls(f[1][j][k][l][0],f[0][j][k][m][l]*24%MOD);pls(f[1][j][k][l][0],f[0][j][k][0][l]*23%MOD);}
		}
	}
	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j)
		pls(f[1][i][j][0][0],(f[1][i][j][0][1]+f[1][i][j][0][2]+f[1][i][j][1][0]+f[1][i][j][1][1]+f[1][i][j][1][2]+f[1][i][j][2][0]+f[1][i][j][2][1]+f[1][i][j][2][2])%MOD);
	for(int i=0;i<=n;++i) for(int j=1;j<=n;++j) pls(f[1][i][j][0][0],f[1][i][j-1][0][0]);
	for(int i=0;i<=n;++i) for(int j=1;j<=n;++j) pls(f[1][j][i][0][0],f[1][j-1][i][0][0]);
	g[2][0][0][0]=25*25;g[2][1][1][0]=g[2][1][0][1]=25;g[2][2][1][1]=1;
	for(int i=3;i<=n;++i) for(int j=0;j<=i;++j){
		if(j) for(int k=0;k<2;++k) pls(g[i][j][k][1],g[i-1][j-1][0][k]);
		for(int k=0;k<2;++k) pls(g[i][j][k][0],(g[i-1][j][0][k]*24+g[i-1][j][1][k]*25)%MOD);
	}
	for(int i=0;i<=n;++i) pls(g[n][i][0][0],(g[n][i][0][1]+g[n][i][1][0]+g[n][i][1][1])%MOD);
	for(int i=1;i<=n;++i) pls(g[n][i][0][0],g[n][i-1][0][0]);
	h[2]=26*26;
	for(int i=3;i<=n;++i) h[i]=h[i-1]*25%MOD;
	ans=h[n];
	for(int i=1;i<27;++i) sub(ans,(g[n][n][0][0]+MOD-g[n][c[i]][0][0])%MOD);
	for(int i=1;i<26;++i) for(int j=26;i^j;--j) pls(ans,query(c[i]+1,c[j]+1));
	write(ans);
	return 0;
}