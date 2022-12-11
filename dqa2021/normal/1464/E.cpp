#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const int mod=998244353;
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
inline void add(int &x,int y){
	x=(x+y)%mod;
}
inline int upd(int x){return x+(x>>31&mod);}

int n,m;
vector<int> e[100010];
int sg[100010];
bool vis[100010];
int dfs(int x){
	if (vis[x]) return sg[x];
	vis[x]=1;
	for (int y: e[x]) dfs(y);
	static int c[100010],tim;
	++tim;
	for (int y: e[x]) c[dfs(y)]=tim;
	for (int &t=sg[x];c[t]==tim;t++);
	return sg[x];
}
int fwt[1<<11];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		e[u].pb(v);
	}
	int P=qpow(n+1,mod-2),inv2=mod+1>>1;
	for (int i=1;i<=n;i++) add(fwt[dfs(i)],P);
	for (int i=0;i<10;i++)
		for (int j=0;j<1024;j++)
			if (j>>i&1){
				int x=fwt[j^(1<<i)],y=fwt[j];
				fwt[j^(1<<i)]=upd(x+y-mod);
				fwt[j]=upd(x-y);
			}
	int ans=0;
	for (int i=0;i<1024;i++) add(ans,qpow(upd(1-fwt[i]),mod-2));
	ans=1LL*ans*qpow(2,mod-1-10)%mod;
	ans=1LL*ans*P%mod;
	ans=upd(1-ans);
	printf("%d\n",ans);
	return 0;
}