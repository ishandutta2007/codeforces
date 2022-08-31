#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,l,t,i,j,k,a[205],c[205],s;
double p[205],dp[205][205][205],ans;
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	fz1(i,n){
		c[i]=i;
		scanf("%lf",&p[i]);p[i]/=100;
	}fz1(i,n){
		scanf("%d",&a[i]);
		if(a[i]==-1)s++;
	}sort(c+1,c+n+1,cmp);
	dp[0][0][min(s,t)]=1;
	fz1(i,n){
		int x=c[i];
		fz0g(j,i){
			fz0g(k,s)if(dp[i-1][j][k]){
				dp[i][j][k]+=dp[i-1][j][k]*(1-p[x]);
				int nxt=k+a[x];
				if(nxt>s)nxt=s;
				if(nxt<0)continue;
				dp[i][j+1][nxt]+=dp[i-1][j][k]*p[x];
			}
		}
	}
	fz(i,l,n)fz0g(j,s) ans+=dp[n][i][j];
	printf("%.10f\n",ans);
	return 0;
}