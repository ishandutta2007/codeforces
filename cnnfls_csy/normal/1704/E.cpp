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
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
int n,m,i,j,a[1005],b[1005],ans,deg[1005];
vector<int> bi[1005],seq;
void dfs(int x)
{
	seq.push_back(x);deg[x]=-1;
	ff(bi[x],it)if(!--deg[*it])dfs(*it);
}
void solve()
{
	read(n);read(m);fz1(i,n)a[i]=b[i]=deg[i]=0,bi[i].clear();
	fz1(i,n)read(a[i]);
	fz1(i,m){int x,y;read(x);read(y);bi[x].push_back(y);deg[y]++;}
	seq.clear();fz1(i,n)if(!deg[i])dfs(i);
	fz1(i,n){
		bool flg=0;fz1(j,n)if(a[j])flg=1;
		if(!flg){printf("%d\n",i-1);return;}
		fz1(j,n) b[j]=a[j];
		fz1(j,n)if(a[j]){
			b[j]--;
			ff(bi[j],it) b[*it]++;
		}
		fz1(j,n) a[j]=b[j];
	}
	ff(seq,it){
		ff(bi[*it],it2){
			a[*it2]=(0ll+a[*it2]+a[*it])%mod;
		}
	}
	printf("%lld\n",(0ll+n+a[seq.back()])%mod);
}
int main()
{
	int t;read(t);
	while(t--){
		solve();
	}
	return 0;
}