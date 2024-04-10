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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
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
const int mod=1e9+7;
int n,m,i,j,sz[200005],dep[200005],bel[200005],dp[200005];
vector<int> bi[200005],son[200005];
int s2(int n)
{
	return (1ll*n*n/2-n+4)%mod;
}
int f1(int x);
int f2(int x,int y); 
int f1(int x)
{
	if(!x) return 1;
	if(sz[x]&1) return 0;
	if(!bel[x]) return sz[x]/2;
	if(dp[x]!=-1) return dp[x];
	int ans=0,i;
	int l=son[bel[x]][0],r=son[bel[x]][1];
	fz1(i,2){
		if(!son[r][1]){
			if(son[r][0]){
				ans=(ans+f2(l,son[r][0]))%mod;
			}
			if(!bel[r]&&dep[r]<=dep[x]){
				ans=(ans+1ll*f1(l)*((dep[x]!=dep[r])+1))%mod;
			}
		}
		else{
			if(!bel[son[r][0]]&&dep[son[r][0]]<=dep[x]){
				ans=(ans+f2(l,son[r][1]))%mod;
			}
			if(!bel[son[r][1]]&&dep[son[r][1]]<=dep[x]){
				ans=(ans+f2(l,son[r][0]))%mod;
			}
		}
		swap(l,r);
	}
	dp[x]=ans;
	return dp[x];
}
int f2(int x,int y)
{
//	cerr<<x<<' '<<y<<endl;
	if(!x||!y) return f1(x+y);
	if((sz[x]+sz[y])&1) return 0;
	if(bi[x].size()==1&&bi[y].size()==1){
		return 1;
	}
	if(bi[x].size()==2&&bi[y].size()==1){
		return f1(son[x][0]);
	}
	if(bi[x].size()==1&&bi[y].size()==2){
		return f1(son[y][0]);
	}
	if(bi[x].size()==2&&bi[y].size()==2){
		return f2(son[x][0],son[y][0]);
	}
	return 0; 
}
int calc(int rt)
{
	int i,ans=0;
	fz0k(i,3){
		int l=(i==0?1:0),r=(i==2?1:2);
		int k=son[rt][i];
		ans=(ans+1ll*f2(son[rt][l],son[k][0])*f2(son[rt][r],son[k][1]))%mod;
		if(bi[k].size()>=2) ans=(ans+1ll*f2(son[rt][l],son[k][1])*f2(son[rt][r],son[k][0]))%mod;
	}
	return 4ll*ans%mod;
}
void dfs(int x,int fa)
{
	sz[x]=1;
	ff(bi[x],it){
		if(*it==fa) continue;
		son[x].push_back(*it);
		dfs(*it,x);
		sz[x]+=sz[*it];
		bel[x]=bel[*it];
		dep[x]=dep[*it]+1;
	}
	if(bi[x].size()==3){
		bel[x]=x;
		dep[x]=0;
	}
	while(son[x].size()<2) son[x].push_back(0);
}
int main()
{
	son[0].push_back(0);
	son[0].push_back(0); 
	memset(dp,-1,sizeof(dp));
	read(n);
	if(n==1){
		puts("2");
		return 0;
	}
	n=n+n;
	fz1(i,n-1){
		int x,y;
		read(x);read(y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	int rt=0;
	fz1(i,n){
		if(bi[i].size()>3){
			puts("0");
			return 0;
		}
		if(bi[i].size()==3){
			rt=i;
			break;
		}
	}
	if(!rt){
		printf("%d\n",s2(n));
		return 0;
	}
	dfs(rt,0);
	printf("%d\n",calc(rt));
	return 0;
}