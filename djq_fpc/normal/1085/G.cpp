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
//struct FastMod
//{
	const unsigned long long _b=mod;
	const __uint128_t _m=18479187002;
	unsigned long long reduce(unsigned long long p)
	{
		unsigned long long q=(unsigned long long)((_m*p)>>64);
		unsigned long long r=p-q*_b;
		return r>=_b?r-_b:r;
	}
//};
int n,m,i,j,fac[2005],f[2005][2005],a[2005][2005],ans,vis1[2005],vis2[2005];
struct BIT{int c[2005];void add(int x,int y){while(x<=n)c[x]+=y,x+=(x&-x);}int query(int x){int s=0;while(x)s+=c[x],x&=(x-1);return s;}}cur1,cur2;
int main()
{
	fac[0]=1;fz1(i,2000) fac[i]=reduce(1ll*fac[i-1]*i);
	f[0][0]=1;fz(i,2,2000) f[0][i]=reduce(1ll*(i-1)*(f[0][i-1]+f[0][i-2]));
	fz1(i,2000){f[i][0]=fac[i];fz1(j,2000-i){f[i][j]=(f[i-1][j]+f[i-1][j+1]);if(f[i][j]>=mod)f[i][j]-=mod;}}
	read(n);fz1(i,n)fz1(j,n)read(a[i][j]);
	fz1(i,n){
		int res=0;
		if(i==1){
			fz1(j,n) cur1.add(j,1);
			fz1(j,n) cur1.add(a[i][j],-1),res=reduce(res+1ll*cur1.query(a[i][j])*fac[n-j]);
		}
		else{
			memset(vis1,0,sizeof(vis1));memset(vis2,0,sizeof(vis2));
			int cnt=0;fz1(j,n) cur2.add(j,1);
			fz1(j,n){
				if(!vis1[a[i-1][j]]) cur1.add(a[i-1][j],1),vis2[a[i-1][j]]=1; else cnt++;
				int c1=cur1.query(a[i][j]-1),c2=cur2.query(a[i][j])-c1-1;
				if(a[i-1][j]<a[i][j]&&cur1.query(a[i-1][j])-cur1.query(a[i-1][j]-1)==1) c1--;
				res=reduce(res+1ll*c1*f[j-1-cnt][n-j-j+1+cnt]);
				res=reduce(res+1ll*c2*f[j-cnt][n-j-j+cnt]);
				cur2.add(a[i][j],-1);
				if(vis2[a[i][j]]) cur1.add(a[i][j],-1),cnt++; else vis1[a[i][j]]=1;
			}
		}
		ans=reduce(1ll*ans*f[0][n]+res);
	}
	cout<<ans<<endl;
	return 0;
}