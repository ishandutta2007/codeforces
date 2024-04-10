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
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar())&&c!='-')if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
int n,m,k,i,j,s[5005][5005],ans;
int qp(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1){
			z=1ll*z*x%mod;
		}
		y/=2;
		x=1ll*x*x%mod;
	}
	return z;
}
int main()
{
	read(n);read(m);read(k);
	s[0][0]=1;
	fz1(i,k){
		fz1(j,i){
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
		}
	}
	int tmp=1;
	fz0g(i,k){
		inc(ans,1ll*tmp*s[k][i]%mod*qp(m,mod-1-i)%mod) 
		tmp=1ll*tmp*(n-i)%mod;
	}
	cout<<ans<<endl;
	return 0;
}