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
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define incm(x,y) {x=((x)+(y))%mod;}
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
int n,m,i,j,a,b,c,s[105][105],le[105][105],up[105][105];
char ans[40005];
int id(int x,int y)
{
	return (x-1)*(2*m)+y;
}
void dfsl(int x,int y,int z)
{
	if(x<1||x>n||y<1||y>m) return;
	if(s[x][y]!=3) return;
	if(le[x][y]) return;
	le[x][y]=z;dfsl(x,y-1,3-z);dfsl(x,y+1,3-z);
}
void dfsu(int x,int y,int z)
{
	if(x<1||x>n||y<1||y>m) return;
	if(s[x][y]!=3) return;
	if(up[x][y]) return;
	up[x][y]=z;dfsu(x-1,y,3-z);dfsu(x+1,y,3-z);
}
int main()
{
	read(n);read(m);read(b);read(a);read(c);
	fz1(i,n){
		fz1(j,m){
			if(c>m){
				s[i][j]=3;
				c--;
			}
			else if(a>0){
				s[i][j]=1;
				a--;
			}
			else if(c>0){
				s[i][j]=3;
				c--;
			}
			else if(b>0){
				s[i][j]=2;
				b--;
			}
		}
	}
	fz1(i,n)fz1(j,m){
		if(s[i][j]!=3&&s[i][j-1]==3){
			dfsl(i,j-1,3-s[i][j]);
		}
		if(s[i][j]!=3&&s[i][j+1]==3){
			dfsl(i,j+1,s[i][j]);
		}
		if(s[i][j]!=3&&s[i-1][j]==3){
			dfsu(i-1,j,3-s[i][j]);
		}
		if(s[i][j]!=3&&s[i+1][j]==3){
			dfsu(i+1,j,s[i][j]);
		}
	}
	fz1(i,n)fz1(j,m)if(s[i][j]==3){
		if(!le[i][j]){
			dfsl(i,j,1);
		}
		if(!up[i][j]){
			dfsu(i,j,1);
		}
	}
	fz1(i,n){
		fz1(j,m){
			int w=id(i+i-1,j+j-1),x=w+1,y=w+m+m,z=y+1;
			if(s[i][j]==1){
				ans[w]='.';ans[x]='.';
				ans[y]='.';ans[z]='.';
				continue;
			}
			if(s[i][j]==2){
				ans[w]='#';ans[x]='#';
				ans[y]='#';ans[z]='#';
				continue;
			}
			if(le[i][j]==1&&up[i][j]==1){
				ans[w]='.';ans[x]='/';
				ans[y]='/';ans[z]='#';
				continue;
			}
			if(le[i][j]==2&&up[i][j]==2){
				ans[w]='#';ans[x]='/';
				ans[y]='/';ans[z]='.';
				continue;
			}
			if(le[i][j]==1&&up[i][j]==2){
				ans[w]='\\';ans[x]='#';
				ans[y]='.';ans[z]='\\';
				continue;
			}
			if(le[i][j]==2&&up[i][j]==1){
				ans[w]='\\';ans[x]='.';
				ans[y]='#';ans[z]='\\';
				continue;
			}
		}
	}
	fz1(i,n+n){
		fz1(j,m+m){
			putchar(ans[id(i,j)]);
		}
		puts("");
	}
	return 0;
}