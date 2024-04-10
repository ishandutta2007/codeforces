#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=1e9+7;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n;
struct Node{
	int l,r,ilen;
}node[200010];
int p[200010];
int getlen(int x,int y)
{
	if (node[x].r<node[y].l||node[y].r<node[x].l) return 0;
	return min(node[x].r,node[y].r)-max(node[x].l,node[y].l)+1;
}
int main()
{
	n=read(); node[0].l=node[0].r=1e9+1;
	for (int i=1;i<=n;i++) node[i].l=read();
	for (int i=1;i<=n;i++) node[i].r=read();
	for (int i=0;i<=n;i++) node[i].ilen=qpow(node[i].r-node[i].l+1,Mod-2);
	for (int i=1;i<=n;i++)
	{
		int t=getlen(i,i-1);
		p[i]=(1-1LL*node[i].ilen*node[i-1].ilen%Mod*t)%Mod;
		p[0]=(p[0]+p[i])%Mod;
	}
	int ans=0;
	for (int i=1;i<n;i++)
	{
		int a=1LL*node[i].ilen*node[i-1].ilen%Mod*getlen(i,i-1)%Mod,
			b=1LL*node[i].ilen*node[i+1].ilen%Mod*getlen(i,i+1)%Mod;
		int maxl=max(node[i-1].l,max(node[i].l,node[i+1].l)),minr=min(node[i-1].r,min(node[i].r,node[i+1].r));
		int c=(maxl<=minr?1LL*node[i].ilen*node[i-1].ilen%Mod*node[i+1].ilen%Mod*(minr-maxl+1)%Mod:0);
		ans=(ans+2*(1LL-a-b+c))%Mod;
	}
	ans=(ans+p[0]+1LL*p[0]*p[0])%Mod;
	for (int i=1;i<n;i++) ans=(ans-2LL*p[i]*p[i+1])%Mod;
	for (int i=1;i<=n;i++) ans=(ans-1LL*p[i]*p[i])%Mod;
	ans+=ans>>31&Mod;
	printf("%d\n",ans);
	return 0;
}