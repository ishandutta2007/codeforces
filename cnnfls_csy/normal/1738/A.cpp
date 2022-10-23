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
int n,m,i,j;
int a[100005];
void solve()
{
	vector<int> v0,v1,m0,m1;
	long long ans=0,sum;
	read(n);fz1(i,n)read(a[i]);
	fz1(i,n){
		int x;read(x);
		if(a[i]) v1.push_back(x); else v0.push_back(x);
	}
	sort(v0.begin(),v0.end());sort(v1.begin(),v1.end());
	reverse(v0.begin(),v0.end());reverse(v1.begin(),v1.end());
	sum=0;
	fz0k(i,max(v0.size(),v1.size())){
		if(i<v0.size()){
			sum+=v0[i];
			if(i<v1.size()) sum+=v0[i];
		}
		if(i<v1.size()){
			sum+=v1[i];
			if(i+1<v0.size()) sum+=v1[i];
		}
	}
	ans=max(ans,sum);
	sum=0;
	fz0k(i,max(v0.size(),v1.size())){
		if(i<v0.size()){
			sum+=v0[i];
			if(i+1<v1.size()) sum+=v0[i];
		}
		if(i<v1.size()){
			sum+=v1[i];
			if(i<v0.size()) sum+=v1[i];
		}
	}
	ans=max(ans,sum);
	printf("%lld\n",ans);
}
int main()
{
	int t;read(t);
	while(t--) solve();
	return 0;
}