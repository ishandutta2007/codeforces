//My rating is 1064.
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
#define mod 1000000007
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int fac[1000005],inv[1000005],fi[1000005];
int np[1000005],mid[1000005],mxd[1000005],mul[1000005];
int c1[1000005],c2[1000005],sz[1000005];
int to1[1000005],to2[1000005];
int n,i,j,a[1000005];
int num(int x){if(x==1)return 1;return n/x;}
int main()
{
	fac_init(1000002)
//	freopen("permutation.in","r",stdin);
//	freopen("permutation.out","w",stdout);
	read(n);
	fz(i,2,n)if(!np[i]){
		mid[i]=mxd[i]=i;c2[n/i]++;
		fz(j,2,n/i){np[i*j]=1;if(!mid[i*j])mid[i*j]=i;mxd[i*j]=i;}
	}
	mul[1]=mid[1]=mxd[1]=sz[1]=1;c1[1]++;c2[1]++;
	fz(i,2,n){
		mul[i]=1;int t=i;
		while(t!=1){int tt=mid[t];while(t%tt==0)t/=tt;mul[i]*=tt;sz[i]++;}
		c1[mul[i]]++; 
	}
	fz1(i,n)read(a[i]);
	fz1(i,n)if(a[i]!=0){
		if(sz[i]!=sz[a[i]]) return puts("0"),0;
		int x=mxd[i],y=mxd[a[i]];
		if(num(x)!=num(y)) return puts("0"),0;
		if(to1[x]&&to1[x]!=y) return puts("0"),0;
		if(to2[y]&&to2[y]!=x) return puts("0"),0;
		if(!to1[x]&&!to2[y]) c2[num(x)]--;
		to1[x]=y;to2[y]=x;c1[mul[i]]--;
	}
	int ans=1;
	fz1(i,n) ans=1ll*ans*fac[c1[i]]%mod;
	fz1(i,n) ans=1ll*ans*fac[c2[i]]%mod;
	cout<<ans<<endl;
	return 0;
}