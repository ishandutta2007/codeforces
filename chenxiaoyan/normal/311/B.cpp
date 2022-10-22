/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=100000,M=100000;
int n,m,s;
int d[N+1];
int a[M+1],Sum[M+1];
int dp[2][M+1];
int q[N],head,tail;
double f(int i,int k,int o){
	return 1.*((dp[i-1&1][k]+Sum[k])-(dp[i-1&1][o]+Sum[o]))/(k-o);
}
signed main(){
	cin>>n>>m>>s;
	for(int i=2;i<=n;i++)cin>>d[i],d[i]+=d[i-1];
	for(int i=1;i<=m;i++){
		int h,t;
		cin>>h>>t;
		a[i]=t-d[h];
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)Sum[i]=Sum[i-1]+a[i];
	for(int i=1;i<=m;i++)dp[0][i]=inf;
	for(int i=1;i<=s;i++){
		head=tail=0;
		q[tail++]=0;
		for(int j=1;j<=m;j++){
			while(head+1<tail&&f(i,q[tail-2],q[tail-1])>=f(i,q[tail-1],j))tail--;
			q[tail++]=j;
			while(head+1<tail&&f(i,q[head],q[head+1])<=a[j])head++;
			dp[i&1][j]=dp[i-1&1][q[head]]+a[j]*(j-q[head])-(Sum[j]-Sum[q[head]]);
		}
	}
	cout<<dp[s&1][m];
	return 0;
}