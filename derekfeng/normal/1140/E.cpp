#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	short res=0;
	if (ch=='-') res=1,ch=getchar();
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	if (res) x*=-1;
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const ll MOD=998244353;
ll mypow(ll a,int x){
	ll res=1,ans=a;
	while (x>0){
		if (x%2==1){
			x--;
			res*=ans; 
			res%=MOD;
			continue;
		}
		ans*=ans;
		ans%=MOD;
		x/=2;
	}
	return res;
}
int n,k,a[2][100004];
ll dp[2][100004];
void init(){
	dp[0][2]=1,dp[1][2]=0;
	dp[0][3]=k-2,dp[1][3]=k-1;
	for (int i=4;i<=1e5;i++){
		dp[1][i]=(dp[1][i-2]*(k-1)+dp[0][i-2]*(k-1)%MOD*(k-2))%MOD;
		dp[0][i]=(dp[1][i-2]*(k-2)+dp[0][i-2]*((1ll*(k-1)*(k-1)-(k-2))%MOD))%MOD;
	}
}
int n_[2];
ll ans[2];
void go(int w){
	if (n_[w]==0) return;
	int l=1,r=n_[w];
	while(l<=n_[w] && a[w][l]==-1) l++,ans[w]=ans[w]*(k-1)%MOD;
	if (l==n_[w]+1){
		ans[w]=mypow(k-1,n_[w]-1)*k%MOD;
		return;
	}
	while(r>=1 && a[w][r]==-1) r--,ans[w]=ans[w]*(k-1)%MOD;
	if (l==r)
		return;
	for (int i=l;;){
		int j=i+1;
		for (;a[w][j]==-1;j++);
		if (a[w][j]==a[w][i]) ans[w]=(ans[w]*dp[1][j-i+1])%MOD;
		else ans[w]=(ans[w]*dp[0][j-i+1])%MOD;
		if (j==r) return;
		i=j;
	}
}
int main(){
	ans[0]=1,ans[1]=1;
	read(n),read(k);
	init();
	for (int i=0;i<n;i++)
		read(a[i%2][(i+2)/2]);
	n_[0]=(n+1)/2,n_[1]=n/2;
	for (int i=0;i<2;i++) go(i);
	write(ans[0]*ans[1]%MOD);
}