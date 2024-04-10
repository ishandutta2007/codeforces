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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
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
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int mod;
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
int n,m,i,j,fac[2005],inv[2005],fi[2005];
int binom(int x,int y){return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;}
int f[2005][2005],sf[2005][2005],res[2005];
vector<int> bi[2005];
int fpre[2005],fsuf[2005],g[2005];
void dfs(int x,int fa)
{
	int i,j;
	ff(bi[x],it)if(*it!=fa) dfs(*it,x);
	if(bi[x].size()==1){
		fz1(i,n-1) f[x][i]=1;
	}
	else{
		fz1(i,n-1){
			int cur=1;
			ff(bi[x],it)if(*it!=fa) cur=1ll*cur*sf[*it][i]%mod;
			f[x][i]=(f[x][i]+cur)%mod;
		}
		ff(bi[x],it)if(*it!=fa){
			g[*it]=0;
		}
		fz1(i,n-1){
			int cur=1;
			ff(bi[x],it)if(*it!=fa){
				fpre[*it]=cur;
				cur=1ll*cur*sf[*it][i]%mod;
			}
			reverse(bi[x].begin(),bi[x].end());
			cur=1;
			ff(bi[x],it)if(*it!=fa){
				fsuf[*it]=cur;
				cur=1ll*cur*sf[*it][i]%mod;
			}
			reverse(bi[x].begin(),bi[x].end());
			ff(bi[x],it)if(*it!=fa){
				f[x][i]=(f[x][i]+1ll*f[*it][i]*g[*it])%mod;
				g[*it]=(g[*it]+1ll*fpre[*it]*fsuf[*it])%mod;
			}
		}
	}
	fz1(i,n-1) sf[x][i]=(sf[x][i-1]+f[x][i])%mod;
}
int main()
{
	read(n);read(mod);fac_init(2002);
	fz1(i,n-1){int x,y;read(x);read(y);bi[x].push_back(y);bi[y].push_back(x);}
	fz1(i,n-1) res[i]=1;
	ff(bi[1],it){
		dfs(*it,1);
		fz1(i,n-1) res[i]=1ll*res[i]*sf[*it][i]%mod;
	}
	fz1(i,n-1){
		fz1(j,i-1){
			res[i]=(res[i]+1ll*(mod-res[j])*binom(i,j))%mod;
		}
	}
	fz1(i,n-1) printf("%d%c",res[i],spln(i+1,n));
	return 0;
}