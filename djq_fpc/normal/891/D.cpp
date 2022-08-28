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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
    char c;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
    x*=f;
}
int n,m,i,j,fa[500005],sz[500005],c[500005],f[500005],g[500005];
long long sf[500005][2],sg[500005][2],sum[500005][4][2],ans;
vector<int> bi[500005];
void dfs1(int x,int p)
{
	fa[x]=p;sz[x]=1;
	ff(bi[x],it){
		if(*it==p)continue;
		dfs1(*it,x);sz[x]+=sz[*it];
		if(f[*it]==1)c[x]++;
		if(f[*it]==-1)c[x]+=2;
	}
	if(c[x]>1) f[x]=-1; else f[x]=!c[x];
}
void dfs2(int x,int p)
{
	if(!p)g[x]=0;
	else{
		int cc=c[p];
		if(f[x]==1)cc--;
		if(f[x]==-1)cc-=2;
		if(g[p]==1)cc++;
		if(g[p]==-1)cc+=2;
		if(cc>1)g[x]=-1;else g[x]=!cc;
	}
	ff(bi[x],it){
		if(*it==p)continue;
		dfs2(*it,x);
	}
}
void dfs3(int x,int p)
{
	ff(bi[x],it){
		if(*it==p)continue;
		dfs3(*it,x);
		int cc=c[x];
		if(f[*it]==1)cc--;
		if(f[*it]==-1)cc-=2;
		if(cc>1)continue;
		if(cc==0){
			sf[x][0]+=sf[*it][1];
			sf[x][1]+=sf[*it][0];
		}
		else{
			sf[x][0]+=sf[*it][0];
		}
	}
	if(!c[x])sf[x][0]++;
}
void dfs4(int x,int p)
{
	int cc=c[x],i;
	if(cc<=3){
		fz0k(i,2)sum[x][cc][i]+=sg[x][i];
	}
	if(g[x]==1)cc++;
	if(g[x]==-1)cc+=2;
	ff(bi[x],it)if(*it!=p){
		int ccc=cc;
		if(f[*it]==1)ccc--;
		if(f[*it]==-1)ccc-=2;
		if(ccc<=3){
			fz0k(i,2)sum[x][ccc][i]+=sf[*it][i];
		}
	}
	ff(bi[x],it)if(*it!=p){
		int ccc=cc;
		if(f[*it]==1)ccc--;
		if(f[*it]==-1)ccc-=2;
		if(ccc<=3){
			fz0k(i,2)sum[x][ccc][i]-=sf[*it][i];
		}
		fz(i,(f[*it]==-1?2:f[*it]),3){
			int nc=i-(f[*it]==-1?2:f[*it]);
			if(nc>1)continue;
			if(nc==0){
				sg[*it][0]+=sum[x][i][1];
				sg[*it][1]+=sum[x][i][0];
			}
			else{
				sg[*it][0]+=sum[x][i][0];
			}
		}
		if(ccc==0)sg[*it][0]++;
		dfs4(*it,x);
		if(ccc<=3){
			fz0k(i,2)sum[x][ccc][i]+=sf[*it][i];
		}
	}
}
int main()
{
//	freopen("match.in","r",stdin);
//	freopen("match.out","w",stdout);
	read(n);
	if(n&1){puts("0");return 0;}
	fz1(i,n-1){
		int x,y;read(x);read(y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs1(1,0);dfs2(1,0);dfs3(1,0);dfs4(1,0);
	fz(i,2,n){
		if(sz[i]&1){
			ans+=sf[i][0]*sg[i][0];
		}
		else if(!f[i]&&!g[i]){
			ans+=1ll*sz[i]*(n-sz[i]);
		}
	}
	cout<<ans<<endl;
    return 0;
}