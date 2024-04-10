#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[400004];
int cnum[21];
ll dp[1200004];
ll cntp[21],d[400004][20];
ll diff[21][21];
int main(){
	read(n);
	for (int i=0;i<1200004;i++) dp[i]=1e17;
	for (int i=1;i<=n;i++)read(a[i]),a[i]--,cnum[a[i]]++,cntp[a[i]]+=i;
	for (int i=n;i>=1;i--){
		for (int j=0;j<20;j++)d[i][j]=d[i+1][j];
		d[i][a[i]]++;
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<20;j++)
			diff[a[i]][j]+=d[i][j];
	dp[0]=0;
	for (int i=1;i<(1<<20);i++)
		for (int j=0;j<20;j++)if((1<<j)&i){
			if (cnum[j]==0){
				dp[i]=min(dp[i],dp[i^(1<<j)]);
				continue;
			}
			int havego=0;
			ll now=cntp[j],wants;
			for (int k=0;k<20;k++) if (k!=j && ((1<<k)&i)>0)
				havego+=cnum[k],now+=diff[j][k];
			wants=1ll*(havego+1+havego+cnum[j])*cnum[j]/2; 
			dp[i]=min(dp[i],dp[i^(1<<j)]+now-wants);
		}
	write(dp[(1<<20)-1]);
}