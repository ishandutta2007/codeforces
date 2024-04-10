#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iostream>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
template<typename T,int U>
void PutMat(T a[][U],int n,int m)
{
	Fr(i,1,n){Fr(j,1,m)cout<<a[i][j]<<' ';cout<<'\n';}
	cout<<'\n';
}
#define DMat(a,n,m) (printf(#a"[%d][%d]:\n",n,m),PutMat(a,n,m))
struct Min_op{};
template<typename T>
struct Min_tmp{T x;Min_tmp(T a):x(a){}};
template<typename T>
Min_tmp<T> operator<<(T a,Min_op){return Min_tmp<T>(a);}
template<typename T>
T operator<<(Min_tmp<T> op,T b){return min(op.x,b);}
template<typename T>
T operator>>(Min_tmp<T> op,T b){return max(op.x,b);}
template<typename T>
struct min_eq_tmp{T* x;min_eq_tmp(T* a):x(a){}};
template<typename T>
min_eq_tmp<T> operator>>(T& a,Min_op){return min_eq_tmp<T>(&a);}
template<typename T>
void operator<<(min_eq_tmp<T> op,T b){*op.x=min(*op.x,b);}
template<typename T>
void operator>>(min_eq_tmp<T> op,T b){*op.x=max(*op.x,b);}
#define Min <<Min_op()<<
#define Max <<Min_op()>>
#define min_eq >>Min_op()<<
#define max_eq >>Min_op()>>

const int MX=1200;
ll Inf=0x3f3f3f3f3f3f3f3fll;
int N;
ll A[MX][MX];
int fcount(ll x,int d)
{
	int cnt=0;
	while(x%d==0)x/=d,++cnt;
	return cnt;
}
ll A2[MX][MX],A5[MX][MX];
ll dp2[MX][MX],dp5[MX][MX];

int main()
{
	scanf("%d",&N);
	bool Zero=0;
	int zx=0;
	Fr(i,1,N)Fr(j,1,N)
	{
		scanf("%lld",A[i]+j);
		if(A[i][j]==0){Zero=1,zx=i,A[i][j]=10;}
	}
	Fr(i,1,N)Fr(j,1,N)
		A2[i][j]=fcount(A[i][j],2),
		A5[i][j]=fcount(A[i][j],5);
	Fr(i,1,N)Fr(j,1,N)
	{
		if(i==1&&j==1){dp2[i][j]=A2[i][j],dp5[i][j]=A5[i][j];continue;}
		dp2[i][j]=dp5[i][j]=Inf;
		if(i>1)
			dp2[i][j] min_eq dp2[i-1][j]+A2[i][j],
			dp5[i][j] min_eq dp5[i-1][j]+A5[i][j];
		if(j>1)
			dp2[i][j] min_eq dp2[i][j-1]+A2[i][j],
			dp5[i][j] min_eq dp5[i][j-1]+A5[i][j];
	}
	//DMat(dp2,N,N),DMat(dp5,N,N);
	
	ll ans=dp2[N][N] Min dp5[N][N];
	if(Zero&&ans>=1)
	{
		printf("1\n");
		Fo(i,1,zx)putchar('D');
		Fo(i,1,N)putchar('R');
		Fo(i,zx,N)putchar('D');
		exit(0);
	}
	
	printf("%lld\n",ans);
	auto d=dp2[N][N]<dp5[N][N]?dp2:dp5;
	auto a=dp2[N][N]<dp5[N][N]?A2:A5;
	
	int x=N,y=N;
	char stk[MX*2];
	int tp=0;
	while(1)
	{
		if(x==1&&y==1)break;
		else if(x==1)--y,stk[++tp]='R';
		else if(y==1)--x,stk[++tp]='D';
		else
		{
			if(d[x-1][y]+a[x][y]==d[x][y])--x,stk[++tp]='D';
			else --y,stk[++tp]='R';
		}
	}
	while(tp)putchar(stk[tp--]);
	putchar('\n');
	return 0;
}