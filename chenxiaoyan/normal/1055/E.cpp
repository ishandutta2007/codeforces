/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int inf=0x3f3f3f3f;
const int N=1500,M=N;
int n,m,s,t;
int a[N+1],ord_a[N+1];
pair<int,int> rg[M+1];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.Y>y.Y;
}
int mn[N+1];
int dp[N+1][M+1];
int Sum[N+1];
bool chk(int x){
	for(int i=1;i<=n;i++)Sum[i]=Sum[i-1]+(a[i]<=x);
	for(int i=1;i<=n;i++)for(int j=1;j<=s;j++){
		dp[i][j]=0;
		if(mn[i]<=i)dp[i][j]=Sum[i]-Sum[mn[i]-1]+dp[mn[i]-1][j-1];
		dp[i][j]=max(dp[i][j],dp[i-1][j]);
	}
	return dp[n][s]>=t;
}
int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)cin>>a[i],ord_a[i]=a[i];
	sort(ord_a+1,ord_a+n+1);
	for(int i=1;i<=m;i++)cin>>rg[i].X>>rg[i].Y;
	sort(rg+1,rg+m+1,cmp);
	int now=0,nowans=inf;
	for(int i=n;i;i--){
		while(now+1<=m&&rg[now+1].Y>=i)nowans=min(nowans,rg[now+1].X),now++;
		mn[i]=nowans;
	}
	int ans=n+1;
	for(int i=15;~i;i--)if(ans-(1<<i)>=1&&chk(ord_a[ans-(1<<i)]))ans-=1<<i;
	if(ans==n+1)puts("-1");
	else cout<<ord_a[ans];
	return 0;
}
/*1
10 1 1 8
1 1 1 991992993 1 991992993 3 6664666 1000000000 999999999
3 10
*/
/*2
10 5 2 4
10 11 10 9 4 4 3 2 10 11
1 3
2 5
3 6
5 8
8 10
*/