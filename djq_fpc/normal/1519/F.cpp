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
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,dp[6][5][16005],a[6],b[6],g[6][6];
int gth()
{
	int s=0,i;
	fz0k(i,n){
		s=s*5+a[i];
	}
	return s;
}
void gta(int x)
{
	int i;
	fd0k(i,n){
		a[i]=x%5;
		x/=5;
	}
}
int dfs(int x,int y,int h)
{
	if(x==-1){
		if(h==0) return 0;
		return 0x3f3f3f3f;
	}
	if(y==0){
		return dfs(x-1,(x==0?0:b[x-1]),h);
	}
	if(dp[x][y][h]!=-1) return dp[x][y][h];
	dp[x][y][h]=dfs(x-1,(x==0?0:b[x-1]),h);gta(h);
	vector<pair<pair<int,int>,int> > trs;
	int i,j;
	fz0k(i,n)if(a[i]){
		fz1(j,min(y,a[i])){
			a[i]-=j;
			trs.push_back(make_pair(make_pair(y-j,gth()),g[i][x]));
			a[i]+=j;
		}
	}
	ff(trs,it){
		dp[x][y][h]=min(dp[x][y][h],dfs(x,it->first.first,it->first.second)+it->second);
	}
//	if(dp[x][y][h]<0x3f3f3f3f) cerr<<x<<' '<<y<<' '<<h<<' '<<dp[x][y][h]<<endl;
	return dp[x][y][h];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	read(n);read(m);
	int sa=0,sb=0;
	fz0k(i,n){
		read(a[i]);
		sa+=a[i];
	}
	fz0k(i,m){
		read(b[i]);
		sb+=b[i];
	}
	fz0k(i,n)fz0k(j,m) read(g[i][j]);
	if(sa>sb){
		puts("-1");
		return 0; 
	}
	printf("%d\n",dfs(m-1,b[m-1],gth()));
	return 0;
}