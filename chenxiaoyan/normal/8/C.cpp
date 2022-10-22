/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int sq(int x){return x*x;}
int lbt(int x){return __builtin_ffs(x);}
int lowbit(int x){return x&-x;}
const int N=24;
int xs,ys;
int n;
int x[N+1],y[N+1]; 
int dp[1<<N],pa[1<<N];
int main(){
	cin>>xs>>ys>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<1<<n;i++){
		int i0=lbt(i);
		dp[i]=dp[i^lowbit(i)]+2*(sq(x[i0]-xs)+sq(y[i0]-ys));
		for(int j=1;j<=n;j++)if(j!=i0&&i&1<<j-1)
			if(dp[i^lowbit(i)^1<<j-1]+sq(x[i0]-xs)+sq(y[i0]-ys)+sq(x[i0]-x[j])+sq(y[i0]-y[j])+sq(x[j]-xs)+sq(y[j]-ys)<dp[i])
				dp[i]=dp[i^lowbit(i)^1<<j-1]+sq(x[i0]-xs)+sq(y[i0]-ys)+sq(x[i0]-x[j])+sq(y[i0]-y[j])+sq(x[j]-xs)+sq(y[j]-ys),
				pa[i]=j;
	}
	cout<<dp[(1<<n)-1]<<"\n0 ";
	int now=(1<<n)-1;
	while(now){
		cout<<lbt(now)<<" ";
		if(pa[now])cout<<pa[now]<<" ";
		now^=lowbit(now)|(pa[now]?1<<pa[now]-1:0);
		cout<<"0 ";
	}
	return 0;
}