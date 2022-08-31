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
int s1(int k){return 1ll*k*(k+1)/2%mod;}
int s2(int k){return 1ll*k*(k+1)/2%mod*(k+k+1)%mod*(mod+1)/3%mod;}
int n,t,i,j,ans,allx[2005],ally[2005],a[2005];
map<int,int> mpx,mpy;
int pre[2005],suf[2005];void del(int x){suf[pre[x]]=suf[x];pre[suf[x]]=pre[x];}
void solve(int lx,int ly,int num)
{
//	cerr<<lx<<' '<<ly<<' '<<num<<endl;
	int x=t*2-lx+1,y=t*2-ly+1;
	if(x<0||y<0) return;
	
	int res=1ll*t*x%mod*y%mod,i;
	int k=min(t,min((x-1)/2,(y-1)/2));
	
//	fz1(i,k) res=(res+1ll*(mod-(x-i-i))*(y-i-i))%mod;
	res=(res+1ll*(mod-k)*x%mod*y)%mod;
	res=(res+2ll*(x+y)*s1(k))%mod;
	res=(res+4ll*(mod-s2(k)))%mod;
	
	if(!(num&1)) ans=(ans-res+mod)%mod; else ans=(ans+res)%mod; 
}
int main()
{
//	freopen("fire.in","r",stdin);freopen("fire.out","w",stdout);
//	int tt;read(tt);while(tt--)
	{
		mpx.clear();mpy.clear();ans=0;
		read(n);read(t);fz1(i,n) read(allx[i]),read(ally[i]),mpx[allx[i]]++,mpy[ally[i]]++;
		int rk=0;ff(mpx,it) it->second=(rk+=it->second);rk=0;ff(mpy,it) it->second=(rk+=it->second);
		fz1(i,n) a[mpx[allx[i]]--]=mpy[ally[i]]--;sort(allx+1,allx+n+1);sort(ally+1,ally+n+1);
		fz1(i,n) solve(0,0,1);
		fz1(i,n){
			fz1(j,n)pre[j]=j-1,suf[j]=j+1;suf[0]=1;pre[n+1]=n;fz1(j,i-1)del(a[j]);
			fd(j,n,i+1){
				if(pre[a[j]]==a[i]){
					solve(allx[j]-allx[i],ally[a[j]]-ally[a[i]],2);
					if(suf[a[j]]<=n) solve(allx[j]-allx[i],ally[suf[a[j]]]-ally[a[i]],3);
					if(pre[a[i]]>=1) solve(allx[j]-allx[i],ally[a[j]]-ally[pre[a[i]]],3);
					if(suf[a[j]]<=n&&pre[a[i]]>=1) solve(allx[j]-allx[i],ally[suf[a[j]]]-ally[pre[a[i]]],4);
				}
				if(suf[a[j]]==a[i]){
					solve(allx[j]-allx[i],ally[a[i]]-ally[a[j]],2);
					if(suf[a[i]]<=n) solve(allx[j]-allx[i],ally[suf[a[i]]]-ally[a[j]],3);
					if(pre[a[j]]>=1) solve(allx[j]-allx[i],ally[a[i]]-ally[pre[a[j]]],3);
					if(suf[a[i]]<=n&&pre[a[j]]>=1) solve(allx[j]-allx[i],ally[suf[a[i]]]-ally[pre[a[j]]],4);
				}
				del(a[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}