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
using namespace std;
int n,m,i,j,dp[55][55][55][55],a[55][55];
int calc(int x,int y,int xx,int yy)
{
	return a[xx][yy]-a[x-1][yy]-a[xx][y-1]+a[x-1][y-1];
}
int dfs(int lx,int rx,int ly,int ry)
{
	if(calc(lx,ly,rx,ry)==0){
		return 0;
	}
	if(dp[lx][rx][ly][ry]!=-1){
		return dp[lx][rx][ly][ry];
	}
	int &f=dp[lx][rx][ly][ry];
	f=max(rx-lx+1,ry-ly+1);
	int i;
	fz(i,lx,rx-1){
		f=min(f,dfs(lx,i,ly,ry)+dfs(i+1,rx,ly,ry));
	}
	fz(i,ly,ry-1){
		f=min(f,dfs(lx,rx,ly,i)+dfs(lx,rx,i+1,ry));
	}
//	cerr<<dp[lx][rx][ly][ry]<<endl;
	return f;
}
int main()
{
	scanf("%d",&n);
	fz1(i,n){
		scanf(" ");
		fz1(j,n){
			char c;
			scanf("%c",&c);
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(c=='#');
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(1,n,1,n));
	return 0;
}