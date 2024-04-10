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
int n,m,i,j,k,l,a,d[14][14],f[1<<14],pf[1<<14],qf[1<<14],sf[1<<14],g[1<<14][14],pg[1<<14][14],qg[1<<14][14],h[1<<14][14][14],ph[1<<14][14][14],cnt[1<<14];
vector<pair<long long,long long> > ans;
int lowbit(int x){return x&(-x);}
void prtg(int x,int y)
{
	printf("%d %d\n",x+1,y+1);
}
void prth(int x,int y,int z)
{
	if(y==z) return;
	prtg(z,ph[x][y][z]);
	prth(x^(1<<z),y,ph[x][y][z]);
}
void prtf(int x)
{
	if(cnt[x]==1) return;
	if(pf[x]!=qf[x]){
		prtg(pg[x^sf[x]][pf[x]],pf[x]);
		prtg(pg[x^sf[x]][qf[x]],qf[x]);
	}
	else{
		prtg(pg[x^sf[x]][pf[x]],pf[x]);
		prtg(qg[x^sf[x]][qf[x]],qf[x]);
	}
	prth(sf[x],pf[x],qf[x]);
	prtf(x^sf[x]);
}
int main()
{
	memset(pf,-1,sizeof(pf));
	memset(qf,-1,sizeof(qf));
	memset(sf,-1,sizeof(sf));
	memset(pg,-1,sizeof(pg));
	memset(qg,-1,sizeof(qg));
	memset(ph,-1,sizeof(ph));
	read(n);read(m);a=(1<<n);
	while (m--){
		int x,y;read(x);read(y);
		d[x-1][y-1]=d[y-1][x-1]=1;
	}
	fz0k(i,a) cnt[i]=__builtin_popcount(i);
	fz0k(i,a) fz0k(j,n) if (!((i>>j)&1)) fz0k(k,n) if ((i>>k)&1) if (d[j][k]){
		if (g[i][j]) {qg[i][j]=k;g[i][j]=2;} else {pg[i][j]=k;g[i][j]=1;}
	}
	fz0k(i,n) h[1<<i][i][i]=1;
	fz0k(i,a) fz0k(j,n) if ((i>>j)&1) fz0k(k,n) if ((i>>k)&1){
		fz0k(l,n) if (((i>>l)&1)&&d[l][k]&&h[i^(1<<k)][j][l]){
			h[i][j][k]=1;
			ph[i][j][k]=l;
		}
	}
	memset(f,0x3f,sizeof(f));
	fz0k(i,n) f[1<<i]=0;
	fz(i,3,a-1) if (lowbit(i)!=i){
		for (j=(i&(i-1));j;j=(i&(j-1))){
			fz0k(k,n) if ((j>>k)&1) fz0k(l,n) if ((j>>l)&1) if (h[j][k][l]){
				if (k!=l){
					if (g[i^j][k]&&g[i^j][l]){
						if (f[i]>f[i^j]+cnt[j]+1){
							f[i]=f[i^j]+cnt[j]+1;
							sf[i]=j;pf[i]=k;qf[i]=l;
						}
					}
				}
				else{
					if (g[i^j][k]>=2){
						if (f[i]>f[i^j]+cnt[j]+1){
							f[i]=f[i^j]+cnt[j]+1;
							sf[i]=j;pf[i]=k;qf[i]=l;
						}
					}
				}
			}
		}
	}
	cout<<f[a-1]<<endl;
	prtf(a-1);
	return 0;
}