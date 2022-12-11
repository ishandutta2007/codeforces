#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MOD=1e9+7;
struct mint{int x;mint(int x=0):x(x){}};
inline mint operator+  (mint a,mint b){return a.x+b.x<MOD?a.x+b.x:a.x+b.x-MOD;}
inline mint operator-  (mint a){return MOD-a.x;}
inline mint operator-  (mint a,mint b){return a+-b;}
inline mint operator*  (mint a,mint b){return 1LL*a.x*b.x%MOD;}
inline mint operator<< (mint x,int y){mint r=1;for(;y;y>>=1,x=x*x)if(y&1)r=r*x;return r;}
inline mint operator~  (mint x){return x<<MOD-2;}
inline mint operator/  (mint a,mint b){return a*~b;}
inline mint&operator+= (mint&a,mint b){return a=a+b;}
inline mint&operator-= (mint&a,mint b){return a=a-b;}
inline mint&operator*= (mint&a,mint b){return a=a*b;}
inline mint&operator<<=(mint&x,int y){return x=x<<y;}
inline mint&operator/= (mint&a,mint b){return a=a/b;}
#define MN 100000
#define K 450
char s[MN+5];
int u[MN+5],cnt;
mint f[MN+5],r[MN+5],S[K][MN+5],p[MN+5];
void cal(int m)
{
	if(u[m])return;u[m]=++cnt;
	for(int i=m;i<=MN;++i)S[cnt][i]=S[cnt][i-1]+p[i]*f[i-1]*r[i-m]*r[m-1];
}
int main()
{
	int n=read(),m,i,x;
	for(f[0]=p[0]=i=1;i<=MN;++i)f[i]=f[i-1]*i,p[i]=p[i-1]*25/26;
	for(r[i=MN]=~f[MN];i--;)r[i]=r[i+1]*(i+1);
	scanf("%s",s);cal(m=strlen(s));
	while(n--)
	{
		i=read();
		if(i==1)scanf("%s",s),cal(m=strlen(s));
		else x=read(),printf("%d\n",S[u[m]][x]*(mint(26)<<x)/(mint(25)<<m));
	} 
}