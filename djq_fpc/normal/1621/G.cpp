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
const int mod=1e9+7;
int n,m,i,j,a[200005],pos[200005],c[200005],f[200005],g[200005],h[200005],ans;
map<int,int> mp;
void solve()
{
	mp.clear();ans=0;
	read(n);fz1(i,n)read(a[i]),mp[a[i]]++;
	int num=0;ff(mp,it) num+=it->second,it->second=num;
	fz1(i,n) pos[a[i]=mp[a[i]]--]=i;
	fz1(i,n) c[i]=0;
	fz1(i,n){
		f[i]=1;int x=a[i];
		while(x) f[i]=(f[i]+c[x])%mod,x-=(x&-x);
		x=a[i];while(x<=n) c[x]=(c[x]+f[i])%mod,x+=(x&-x);
	}
	fz1(i,n) c[i]=0;
	fd1(i,n){
		g[i]=1;int x=n-a[i]+1;
		while(x) g[i]=(g[i]+c[x])%mod,x-=(x&-x);
		x=n-a[i]+1;while(x<=n) c[x]=(c[x]+g[i])%mod,x+=(x&-x);
	}
	fz1(i,n) c[i]=0;
	int cur=0;j=n;
	fd1(i,n){
		if(cur==0||cur<pos[i]){
			if(cur){
				while(j>i){
					int p=pos[j];
					int x=n-p+1;
					while(x<=n) c[x]=(c[x]-h[p]+mod)%mod,x+=(x&-x);
					j--;
				}
			}
			cur=pos[i];h[cur]=1;
			int x=n-cur+1;while(x<=n) c[x]=(c[x]+h[cur])%mod,x+=(x&-x);
		}
		else{
			int p=pos[i];
			h[p]=0;
			int x=n-p+1;
			while(x) h[p]=(h[p]+c[x])%mod,x-=(x&-x);
			x=n-p+1;while(x<=n) c[x]=(c[x]+h[p])%mod,x+=(x&-x);
		}
	}
	fz1(i,n) ans=(ans+1ll*f[i]*(g[i]-h[i]+mod))%mod;
	printf("%d\n",ans);
}
int main()
{
	int t;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}