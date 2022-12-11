#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long double ld;
const ld eps=1e-9;

int n;
ld mp[1010][1010];
ld f[1010],g[1010];
bool vis[1010];
bool work(){
	int x=-1;
	for (int i=1;i<=n;i++)
		if (!vis[i]&&fabs(g[i]-1)>eps&&(x==-1||f[i]/(1-g[i])<f[x]/(1-g[x])))
			x=i;
	f[x]/=(1-g[x]); vis[x]=1;
	if (x==1) return 1;
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			f[i]+=g[i]*mp[i][x]*f[x];
			g[i]*=(1-mp[i][x]);
		}
	return 0;
}
int main()
{
	n=read();
	if (n==1) return puts("0.000000000000"),0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			mp[i][j]=0.01*read();
		}
	f[n]=0,g[n]=1; vis[n]=1;
	for (int i=1;i<n;i++) g[i]=1,f[i]=1;
	for (int i=1;i<n;i++){
		f[i]+=g[i]*mp[i][n]*f[n];
		g[i]*=(1-mp[i][n]);
	}
	while (!work());
	printf("%.12lf\n",(double)f[1]);
	return 0;
}