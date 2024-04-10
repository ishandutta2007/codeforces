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
const int mod=998244353;
int n,m,i,j,k,l;
int f[200005][1<<3][1<<3];
string st;
int main()
{
	rdst(st,200005);n=st.size();reverse(st.begin(),st.end());
	f[n][7][7]=1;
	fd1(i,n)fz0k(j,8)fz0k(k,8)if(f[i][j][k]){
//		cerr<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<endl;
		int lim=(st[i-1]=='0'?(7^j):7);
		fz0k(l,8)if((l&lim)==l){
			int x=(l&1);
			int y=((l>>1)&1);
			int z=((l>>2)&1);
			int a=x^y;
			int b=x^z;
			int c=y^z;
			int nk=k;
			if(a|b|c){
				if(!a) nk&=6;
				if(!b) nk&=5;
				if(!c) nk&=3;
			}
			int nj=j;
			if(st[i-1]=='1') nj&=l;
			f[i-1][nj][nk]+=f[i][j][k];
			if(f[i-1][nj][nk]>=mod) f[i-1][nj][nk]-=mod;
		}
	}
	int ans=0;fz0k(i,8) ans=(ans+f[0][i][0])%mod;
	cout<<ans<<endl;
	return 0;
}