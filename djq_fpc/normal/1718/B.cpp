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
int t,n,m,i,j,a[105];
long long fib[105];
map<long long,int> mp;
void solve()
{
	long long sum=0;int lst=0;
	read(n);fz1(i,n) read(a[i]),sum+=a[i];
	if(!mp.count(sum)){puts("NO");return;}
	int t=mp[sum];
	while(t>=0){
		int s=-1;
		fz1(i,n)if(i!=lst&&a[i]>=fib[t]){
			if(s==-1||a[i]>a[s]) s=i;
		}
		if(s==-1){puts("NO");return;}
		lst=s;a[s]-=fib[t];t--;
	}
	puts("YES");
}
int main()
{
	fib[0]=fib[1]=1;
	for(i=2;i<=60;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	long long sum=0;
	fz0g(i,60){
		sum+=fib[i];
		mp[sum]=i;
	}
//	cerr<<sum<<endl;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}