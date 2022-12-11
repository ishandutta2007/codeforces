#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
int a[2001],b[2001],n;
short f[2000002<<2];
inline int readint(){
	register char c=getchar();
	for(;!isdigit(c);c=getchar());
	register int d=0;
	for(;isdigit(c);c=getchar())
	d=(d<<3)+(d<<1)+(c^'0');
	return d;
}
int main(){
	register int ans=0;
	n=readint();
	memset(f,0,sizeof f);
	for(register int i=1;i<=n;++i)f[a[i]=readint()]=1;
	for(register int i=1;i<=n;++i)f[b[i]=readint()]=1;
	for(register int i=1;i<=n;++i)
	for(register int j=1;j<=n;++j)
	ans+=f[a[i]^b[j]];
	puts((ans&1)?("Koyomi"):("Karen"));
	return 0;
}