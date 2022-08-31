#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[4005],sz[4005];
int stk[4005],tp,lc[4005],rc[4005];
long long f[4005][4005],g[4005];
vector<int> bi[4005];
void dfs(int x,int fa)
{
	memset(f[x],-0x3f,sizeof(f[x]));
	f[x][0]=0;f[x][1]=1ll*(m-1)*a[x];
	sz[x]=1;
	ff(bi[x],it){
		dfs(*it,x);
		memset(g,-0x3f,sizeof(g));
		int i,j;
		fz0g(i,sz[x])fz0g(j,sz[*it]){
			g[i+j]=max(g[i+j],f[x][i]+f[*it][j]-2ll*i*j*a[x]);
		}
		memcpy(f[x],g,sizeof(f[x]));
		sz[x]+=sz[*it];
	}
}
int main()
{
	read(n);read(m);fz1(i,n)read(a[i]);
	fz1(i,n){
		int lst=0;
		while(tp&&a[stk[tp]]>=a[i]){
			lst=stk[tp--];
		}
		lc[i]=lst;
		if(tp) rc[stk[tp]]=i;
		stk[++tp]=i;
	}
	int rt=stk[1];
	fz1(i,n){
		if(lc[i])bi[i].push_back(lc[i]);
		if(rc[i])bi[i].push_back(rc[i]);
	}
	dfs(rt,0);
	cout<<f[rt][m]<<endl;
	return 0;
}