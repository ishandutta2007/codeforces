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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
int n,m,i,j,fa[4005],cnt[2005];
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
vector<int> vr[4005],vc[4005];
int g[2005][2005],a[2005],b[2005],c;
int solve0()
{
	int i,j,k,ans=(g[1][1]==-1?2:1); // coef of a[1][1]
	fz1(k,n+m)if(fa[k]==k){
		if(vr[k].empty()&&vc[k].empty()) continue;
		int res=0;
		
		// !choose
		int cnt=0;
		ff(vr[k],it) cnt+=(g[*it][1]==-1);
		ff(vc[k],it) cnt+=(g[1][*it]==-1);
		ff(vr[k],it1)ff(vc[k],it2) cnt+=(g[*it1][*it2]==-1);
		res=(res+qp(2,cnt))%mod;
		
		// choose
		int tmp=1;
		ff(vr[k],it){
			if(g[*it][1]==-1) tmp=0;
			else if(a[*it]==1) tmp=(mod-tmp)%mod;
		}
		ff(vc[k],it){
			if(g[1][*it]==-1) tmp=0;
			else if(b[*it]==1) tmp=(mod-tmp)%mod;
		}
		ff(vr[k],it1)ff(vc[k],it2){
			if(g[*it1][*it2]==-1) tmp=2ll*tmp%mod;
		}
		res=(res+tmp)%mod;
		
		ans=1ll*ans*res%mod;
	}
	return ans;
}
int solve1()
{
	if(g[1][1]==-1) return 0; 
	int i,j,k,ans=(c==1?mod-1:1); // coef of a[1][1]
	fz1(k,n+m)if(fa[k]==k){
		if(vr[k].empty()&&vc[k].empty()) continue;
		int res=0;
		
		// choose row
		int tmp=1;
		ff(vr[k],it){
			if(g[*it][1]==-1) tmp=0;
			else if(a[*it]==1) tmp=(mod-tmp)%mod;
		}
		ff(vc[k],it){
			if(g[1][*it]==-1) tmp=2ll*tmp%mod;
		}
		ff(vr[k],it1)ff(vc[k],it2){
			if(g[*it1][*it2]==-1) tmp=2ll*tmp%mod;
		}
		res=(res+tmp)%mod;
		
		// choose col
		tmp=1;
		ff(vr[k],it){
			if(g[*it][1]==-1) tmp=2ll*tmp%mod;
		}
		ff(vc[k],it){
			if(g[1][*it]==-1) tmp=0;
			else if(b[*it]==1) tmp=(mod-tmp)%mod;
		}
		ff(vr[k],it1)ff(vc[k],it2){
			if(g[*it1][*it2]==-1) tmp=2ll*tmp%mod;
		}
		res=(res+tmp)%mod;
		
		ans=1ll*ans*res%mod;
	}
	return ans;
}
int main()
{
	read(n);read(m);
	fz1(i,n+m) fa[i]=i;
	fz1(i,n){
		fz1(j,m){
			char c;
			while(!isdigit(c=getchar())&&c!='?');
			if(c=='?') g[i][j]=-1; else g[i][j]=(c&1);
		}
	}
	if(!(n&1)&&!(m&1)){
		int s=1;
		fz1(i,n)fz1(j,m)if(g[i][j]==-1) s=2ll*s%mod;
		printf("%d\n",s);
		return 0;
	}
	if((n&1)&&!(m&1)){
		fz1(i,n){
			fz1(j,m){
				if(g[i][j]==-1) b[j]=-1,cnt[j]++;
				else if(b[j]!=-1) b[j]^=g[i][j];
			}
		}
		int res=0,tmp=1;
		fz1(i,m) if(b[i]==1) tmp=0; else if(b[i]==-1) tmp=1ll*tmp*qp(2,cnt[i]-1)%mod;
		res=tmp;tmp=1;
		fz1(i,m) if(b[i]==0) tmp=0; else if(b[i]==-1) tmp=1ll*tmp*qp(2,cnt[i]-1)%mod;
		res=(res+tmp)%mod;
		printf("%d\n",res);
		return 0;
	}
	if(!(n&1)&&(m&1)){
		fz1(i,n){
			fz1(j,m){
				if(g[i][j]==-1) a[i]=-1,cnt[i]++;
				else if(a[i]!=-1) a[i]^=g[i][j];
			}
		}
		int res=0,tmp=1;
		fz1(i,n) if(a[i]==1) tmp=0; else if(a[i]==-1) tmp=1ll*tmp*qp(2,cnt[i]-1)%mod;
		res=tmp;tmp=1;
		fz1(i,n) if(a[i]==0) tmp=0; else if(a[i]==-1) tmp=1ll*tmp*qp(2,cnt[i]-1)%mod;
		res=(res+tmp)%mod;
		printf("%d\n",res);
		return 0;
	}
	if((n&1)&&(m&1)){
		fz1(i,n){
			fz1(j,m){
				if(i>1&&j>1){
					if(g[i][j]==-1) fa[fnd(i)]=fnd(j+n);
				}
				if(g[i][j]!=-1){
					a[i]^=g[i][j],b[j]^=g[i][j];
					if((i>1)==(j>1)) ::c^=g[i][j];
				}
			}
		}
		fz(i,2,n) vr[fnd(i)].push_back(i);
		fz(i,2,m) vc[fnd(i+n)].push_back(i);
		int ans=(solve0()+solve1())%mod;
		fz1(i,n) a[i]^=1;
		fz1(i,m) b[i]^=1;
		c^=1;
		ans=(0ll+ans+solve0()+solve1())%mod;
		printf("%lld\n",1ll*ans*qp(2,mod-1-(n+m-1))%mod);
		return 0;
	}
}