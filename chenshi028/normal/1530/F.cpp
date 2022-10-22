#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=(1<<21)+5,MOD=31607;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*b%MOD) if(f&1) res=res*b%MOD;return res;}
int n,a[22][22],b[22][o],mp[o],f[o*4],p[o*2];
inline int lowbit(int x){return x&-x;}
int main(){
	read(n);for(int i=1,inv=qp(10000,MOD-2);i<=n;++i) for(int j=1;j<=n;++j) read(a[i][j]),a[i][j]=a[i][j]*inv%MOD;
	for(int i=2,j=1;j<=n;i<<=1,++j) mp[i]=j;
	for(int i=1;i<=n;++i)
		for(int j=b[i][0]=1;j<(1<<n);++j) b[i][j]=b[i][j^lowbit(j)]*a[mp[lowbit(j)]+1][i]%MOD;
	for(int s=0,E=(1<<n)-1;s<(1<<(n+2));++s) for(int i=f[s]=1;i<=n;++i)
		f[s]=f[s]*(1+MOD-b[i][((s&E)|((s&(E+1))?(1<<(n-i)):0)|((s&(E*2+2))?(1<<(i-1)):0))^E])%MOD;
	for(int i=n+2;i;--i){
		if(i==n+2) for(int s=p[0]=1;s<(1<<n);++s) p[s]=p[s^lowbit(s)]*a[mp[lowbit(s)]+1][mp[lowbit(s)]+1]%MOD;
		else if(i==n+1) for(int s=p[0]=1;s<(1<<n);++s) p[s]=p[s^lowbit(s)]*a[mp[lowbit(s)]+1][n-mp[lowbit(s)]]%MOD;
		else for(int j=p[0]=1;j<=n;++j) p[0]=p[0]*a[i][j]%MOD;
		for(int s=0,E=(1<<n)-1;s<(1<<(i-1));++s)
			f[s]=(f[s]+MOD-f[s|(1<<(i-1))]*p[(i==n+2)?((s&E)|(((n&1)&&(s&(1<<n)))?(1<<(n>>1)):0))^E:(i==n+1)?(s&E)^E:0]%MOD)%MOD;
	}
	write((MOD+1-f[0])%MOD);
	return 0;
}