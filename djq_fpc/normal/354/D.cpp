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
struct ii
{
	int x,y;
}a[100005];
int n,m,i,j,k,cnt[1005],dp[2][1005],lim;
bool cmp(ii x,ii y)
{
	return x.x<y.x;
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,m){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x=a[i].x-a[i].y+1;
	}
	lim=sqrt(m*6)+1;
	sort(a+1,a+m+1,cmp);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=m*3;k=1;
	fz1(i,n){
		memset(cnt,0,sizeof(cnt));
		memset(dp[i&1],0x3f,sizeof(dp[i&1]));
		int ry=n-i+1;
		while(k<=m&&a[k].x==i){
			if(ry-a[k].y+1<=lim) cnt[ry-a[k].y+1]++;
			k++;
		}
		fz(j,2,lim) cnt[j]+=cnt[j-1];
		fz0g(j,lim) dp[i&1][j]=dp[(i-1)&1][j+1]-cnt[j]*3;
		dp[i&1][0]=min(dp[i&1][0],dp[(i-1)&1][0]);
		int mi=0x3f3f3f3f;
		fz0g(j,lim){
			mi=min(mi,dp[(i-1)&1][j]);
			dp[i&1][j]=min(dp[i&1][j],mi+j*(j+1)/2+2-cnt[j]*3);
		}
	}
	cout<<min(dp[n&1][0],dp[n&1][1])<<endl;
	return 0;
}