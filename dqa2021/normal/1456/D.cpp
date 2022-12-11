#include<cstdio>
#include<algorithm>
#include<cctype>
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
typedef long long ll;
const ll INF=1e9+9;

int n;
ll t[5010],p[5010];
ll f[5010]; bool g[5010][5010];
ll getdis(ll x,ll y){return x>y?x-y:y-x;}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) t[i]=read(),p[i]=read();
	
	for (int i=1;i<=n;i++) f[i]=INF;
	f[0]=0;
	for (int i=0;i<=n;i++){
		if (f[i]<=t[i]){
			if (i<n) f[i+1]=min(f[i+1],max(f[i]+getdis(p[i],p[i+1]),t[i]));
			for (int j=i+2;j<=n;j++){
				int s=max(t[i],f[i]+getdis(p[i],p[j]));
				if (s+getdis(p[j],p[i+1])<=t[i+1]) g[i+1][j]=1;
			}
		}
		for (int j=i+1;j<=n;j++){
			if (!g[i][j]) continue;
			//printf("valid g %d %d\n",i,j);
			if (i+1<j){
				g[i+1][j]|=(t[i]+getdis(p[i],p[i+1])<=t[i+1]);
			}
			else{
				if (j<n) f[j+1]=min(f[j+1],max(t[i]+getdis(p[i],p[j+1]),t[j]));
				for (int k=j+2;k<=n;k++){
					int s=max(t[j],t[i]+getdis(p[i],p[k]));
					if (s+getdis(p[k],p[j+1])<=t[j+1]) g[j+1][k]=1;
				}
			}
		}
	}
	//printf("test %lld %d\n",f[n],g[n-1][n]);
	if (f[n]<=t[n]||g[n-1][n]) puts("YES");
	else puts("NO");
	
	return 0;
}