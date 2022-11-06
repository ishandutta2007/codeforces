#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
void putint(LL n)
{
     char a[20];
     int size=0;
     if (n==0)
        putchar('0');
     while (n)
     {
           a[size++]=n%10+48;
           n/=10;
     }
     for (int i=size-1;i>=0;i--)
         putchar(a[i]);
     putchar('\n');
}
int n,m,k;
LL c[110],dp[110][110][110],a[110][110],ans;
const LL INF=1e18;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) cin>>c[i];
	FOR(i,1,n)
		FOR(j,1,m)
			cin>>a[i][j];
	FOR(i,0,n)
		FOR(j,0,m)
			FOR(p,0,k)
				dp[i][j][p]=INF;
	dp[0][0][0]=0;
	FOR(i,0,n-1)
		FOR(j,0,m)
			FOR(p,0,k){
				if (c[i+1]!=0){
					if (c[i+1]!=j) dp[i+1][c[i+1]][p+1]=min(dp[i][j][p],dp[i+1][c[i+1]][p+1]);
					else dp[i+1][j][p]=min(dp[i+1][j][p],dp[i][j][p]);
				}
				else{
					FOR(q,1,m){
						if (q==j) dp[i+1][q][p]=min(dp[i+1][q][p],dp[i][j][p]+a[i+1][q]);
						else dp[i+1][q][p+1]=min(dp[i+1][q][p+1],dp[i][j][p]+a[i+1][q]);
					}
				}
			}
	ans=INF;
	FOR(i,1,m)
		ans=min(ans,dp[n][i][k]);
	if (ans<INF) cout<<ans<<endl; else puts("-1");
	return 0;
}