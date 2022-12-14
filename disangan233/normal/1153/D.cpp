#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define ak *
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
inline ll qpow(ll x,ll y,ll p,ll z=1)
{
 	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(x*z)%p:z;
	return z;
}
char s[10005];
int n,a[300005],tot;
vector<int>v[300005];
int dfs(re u)
{
	re ans=a[u]?1e9:0;
	for(re i=0,sz=v[u].size();i<sz;i++)
	ans=a[u]?min(dfs(v[u][i]),ans):dfs(v[u][i])+ans;
	// cout<<u<<" "<<ans<<endl;
	return (ans!=(int)1e9&&ans!=0)?ans:(tot++,1);
}
int main()
{
	n=read();for(re i=1;i<=n;i++) a[i]=read();
	for(re i=2;i<=n;i++) v[read()].push_back(i);
	cout<<abs(dfs(1)-tot-1);
}