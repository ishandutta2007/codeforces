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
typedef long long i64;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(i64 &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,k,i,j;
int f[105][105][2][2];
int dfs(int c0,int c1,int op,int cur)
{
	if(!c0&&!c1) return (cur==0);
	if(f[c0][c1][op][cur]!=-1) return f[c0][c1][op][cur];
	if(op==0){
		f[c0][c1][op][cur]=0;
		if(c0) f[c0][c1][op][cur]|=dfs(c0-1,c1,op^1,cur);
		if(c1) f[c0][c1][op][cur]|=dfs(c0,c1-1,op^1,cur^1);
	}
	else{
		f[c0][c1][op][cur]=1;
		if(c0) f[c0][c1][op][cur]&=dfs(c0-1,c1,op^1,cur);
		if(c1) f[c0][c1][op][cur]&=dfs(c0,c1-1,op^1,cur);
	}
	return f[c0][c1][op][cur];
}
void solve()
{
	read(n);int c0=0,c1=0;
	fz1(i,n){
		int x;read(x);
		if(x%2==0) c0++; else c1++;
	}
	if(dfs(c0,c1,0,0)) puts("Alice"); else puts("Bob");
}
int main()
{
	memset(f,-1,sizeof(f));
	int t;read(t);
	while(t--) solve();
	return 0;
}