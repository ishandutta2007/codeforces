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
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
typedef long long i64;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(i64 &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
int n,m,k,i,j;
i64 a[100005],pre[100005],suf[100005];
int fac[100005],inv[100005],fi[100005],ans;
int binom(int x,int y)
{
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
void solve()
{
	ans=1;
	read(n);fz0g(i,n+1) pre[i]=suf[i]=0;
	fz1(i,n) read(a[i]);
	fz1(i,n) pre[i]=pre[i-1]+a[i];
	fd1(i,n) suf[i]=suf[i+1]+a[i];
	i=1;j=n;
	while(i<=j){
		i64 cur=min(suf[j],pre[i]);int sl=0,sr=0;
		while(i<=j&&pre[i]==cur) i++,sl++;
		while(i<=j&&suf[j]==cur) j--,sr++;
		if(i<=j){
			int sum=0;
			fz0g(k,min(sl,sr)){
				sum=(sum+1ll*binom(sl,k)*binom(sr,k))%mod;
			}
			ans=1ll*ans*sum%mod;
		}
		else{
			int s=sl+sr-1,sum=0;
			fz0g(k,s){
				sum=(sum+binom(s,k))%mod;
			}
			ans=1ll*ans*sum%mod;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	fac_init(100002);
	int t;read(t);
	while(t--) solve();
	return 0;
}