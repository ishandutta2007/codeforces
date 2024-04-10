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
#define rdst(st,len){static char ss[len];scanf("%s",ss);(st)=ss;}
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
int t,n,m,i,j,res,a[200005];
int c0[200005],c1[200005];
int mxp[200005];
void solve()
{
	read(n);
	fz1(i,n){
		char c;while(!isdigit(c=getchar()));
		a[i]=(c&15);c0[i]=c0[i-1];c1[i]=c1[i-1];(a[i]?c1:c0)[i]++;
	}
	bool flg=1;fz1(i,n-1)if(a[i]>a[i+1])flg=0;
	if(flg){puts("0");return;}
	if(c0[n]==c1[n]){puts("1");return;}
	if(c0[n]<c1[n]){
		fz1(i,n)a[i]^=1;reverse(a+1,a+n+1);
		fz1(i,n)c0[i]=c0[i-1],c1[i]=c1[i-1],(a[i]?c1:c0)[i]++;
	}
	fz0g(i,n)mxp[i]=-1;
	fz0g(i,n){
		int t=c0[i]-c1[i];
		if(t>=0) mxp[t]=max(mxp[t],i);
	}
	res=0;int tar=c0[n]-c1[n],cur=0;
	while(cur<n&&cur<tar&&a[cur+1]==0) cur++;
	while(cur<tar){
		cur=min(tar,c0[mxp[cur]]);
		res++;
	}
	res++;printf("%d\n",res);
}
int main()
{
	read(t);
	while(t--){
		solve();
	}
	return 0;
}