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
int t,n,m,k,a[100005],i,j;
void solve()
{
	read(n);read(m);read(k);
	fz1(i,k)read(a[i]);
	long long sum=0;int rem=0;
	fz1(i,k)if(a[i]/m>=2){
		sum+=a[i]/m;
		if(a[i]/m>2) rem=1;
	}
	if(sum>n&&(sum%2)!=(n%2)){
		if(rem){
			puts("Yes");
			return;
		}
	}
	else if(sum>=n){
		puts("Yes");
		return;
	}
	swap(n,m);
	sum=rem=0;
	fz1(i,k)if(a[i]/m>=2){
		sum+=a[i]/m;
		if(a[i]/m>2) rem=1;
	}
	if(sum>n&&(sum%2)!=(n%2)){
		if(rem){
			puts("Yes");
			return;
		}
	}
	else if(sum>=n){
		puts("Yes");
		return;
	}
	puts("No");
}
int main()
{
	read(t);
	while(t--){
		solve();
	}
	return 0;
}