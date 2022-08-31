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
const int mod=1e9+7;
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
int n,m,q,i,j,k,a[305],d[305],ca[305],A[305][305],g[305][305],C[305][305],v[305][305],sv[305][305],coef[305][305];
vector<int> bi[305];
void getv()
{
	int i,j,k;
	fz1(k,n){
		memcpy(g,A,sizeof(g));
		fz1(i,n){
			g[i][i]=(g[i][i]+mod-k)%mod;
			g[i][n+1]=0;
		}
		g[k][k]=1;
		g[k][n+1]=1;
		fd1(i,n){
			int t=qp(g[i][i],mod-2);
			g[i][i]=1;
			g[i][n+1]=1ll*g[i][n+1]*t%mod;
			fz1(j,i-1){
				g[j][n+1]=(g[j][n+1]+1ll*(mod-g[j][i])*g[i][n+1])%mod;
			}
		}
		fz1(i,n){
			v[k][i]=g[i][n+1];
		}
	}
	fz1(i,n){
		fz1(j,n){
			sv[i][j]=(sv[i][j-1]+v[i][j])%mod;
		}
	}
}
void getc()
{
	int i,j,k;
	fz1(i,n){
		fz1(j,n){
			g[i][j]=v[i][j];
		}
	}
	fz1(i,n){
		C[i][i]=1;
	}
	fz1(i,n){
		int t=qp(g[i][i],mod-2);
		fz1(j,n){
			g[i][j]=1ll*g[i][j]*t%mod;
			C[i][j]=1ll*C[i][j]*t%mod;
		}
		fz1(j,n)if(i!=j){
			int t=g[j][i];
			fz1(k,n){
				g[j][k]=(g[j][k]+1ll*(mod-t)*g[i][k])%mod;
				C[j][k]=(C[j][k]+1ll*(mod-t)*C[i][k])%mod;
			}
		}
	}
}
struct bit
{
	int a[305];
	void init()
	{
		memset(a,0,sizeof(a));
	}
	void build()
	{
		int i;
		fz1(i,n){
			if(i+(i&-i)<=n){
				a[i+(i&-i)]+=a[i];
				if(a[i+(i&-i)]>=mod)a[i+(i&-i)]-=mod;
			}
		}
	}
	void add(int x,int y)
	{
		x++;
		while(x<=n)a[x]+=y,(a[x]>=mod?a[x]-=mod:0),x+=(x&-x);
	}
	int query(int x)
	{
		int s=0;x++;
		while(x)s+=a[x],(s>=mod?s-=mod:0),x-=(x&-x);
		return s;
	}
}tr[305];
int ipw[305][305];
void rebuild()
{
	int i,j;
	fz1(i,n) d[i]=(a[i]>0?0:0x3f3f3f3f);
	fd1(i,n){
		ff(bi[i],it){
			d[i]=min(d[i],d[*it]+1);
		}
	}
	fz1(j,n){
		tr[j].init();
		fz1(i,n)if(d[i]<0x3f3f3f3f){
			coef[j][i]=1ll*C[i][j]*ipw[j][d[i]]%mod;
			tr[j].a[d[i]+1]=(tr[j].a[d[i]+1]+1ll*(a[i]+mod)*coef[j][i])%mod;
		}
		tr[j].build();
	}
}
int main()
{
	fz1(i,300){
		ipw[i][0]=1;
		fz1(j,300){
			ipw[i][j]=qp(i,mod-1-j);
		}
	}
//	freopen("dag.in","r",stdin);
//	freopen("dag.out","w",stdout);
	read(n);fz1(i,n)read(a[i]);
	fz1(i,n) A[i][i]=i;
	fz1(i,n){
		int x,y;read(x);
		while(x--)read(y),A[i][y]=y,bi[i].push_back(y);
	}
	getv();
	getc();
	rebuild();
	read(q);
	while(q--){
		int op;
		read(op);
		if(op==1){
			int k,l,r,ans=0;read(k);read(l);read(r);
			fz1(j,n){
				ans=(ans+1ll*(sv[j][r]-sv[j][l-1]+mod)*qp(j,k)%mod*tr[j].query(min(k,n-1)))%mod;
			}
			fz(i,l,r){
				if(d[i]>k){
					ans=(0ll+ans+a[i]+mod)%mod;
				}
			}
			printf("%d\n",ans);
		}
		else{
			int x,y;read(x);read(y);
			if(a[x]<=0&&a[x]+y>0){
				a[x]+=y;rebuild();
			}
			else{
				a[x]+=y;
				if(d[x]<0x3f3f3f3f){
					fz1(j,n){
						tr[j].add(d[x],1ll*coef[j][x]*y%mod);
					}
				}
			}
		}
	}
	return 0;
}