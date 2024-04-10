#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define ll long long
using namespace std;
int n,k,l[2005],r[2005];
ll A[2005][2005],f[2][2005][2005],g[2005][2005],ans;
void upd_g(int p){
	for (int i=l[p];i<=r[p];i++)
		memset(g[i],0,sizeof(g[i]));
	for (int i=l[p-1];i<=r[p-1]&&i<=r[p];i++)
		for (int j=i;j<=p-1;j++){
			if (i>=l[p]){
				g[i+1][j-i]+=f[(p-1)&1][i][j];
				if (g[i+1][j-i]>=mod)g[i+1][j-i]-=mod;
			}
			else if (j>=l[p]-1)
				g[l[p]][j-l[p]+1]=(g[l[p]][j-l[p]+1]+A[j-i][l[p]-i-1]*f[(p-1)&1][i][j])%mod;
		}
	for (int i=l[p];i<=r[p];i++)
		for (int j=1;i+j<=p;j++)
			g[i+1][j-1]=(g[i+1][j-1]+g[i][j]*j)%mod;
	return;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		l[i]=max(0,x-k),r[i]=min(n,x+k);
	}
	for (int i=0;i<=n;i++)A[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			A[i][j]=(A[i-1][j]+A[i-1][j-1]*j)%mod;
	f[0][0][0]=1;
	for (int i=1;i<=n;i++){
		upd_g(i);
		for (int j=l[i];j<=r[i];j++)
			for (int k=j;k<=i;k++){
				f[i&1][j][k]=f[(i-1)&1][j][k]*k;
				if (k>0)f[i&1][j][k]+=f[(i-1)&1][j][k-1];
				f[i&1][j][k]+=g[j][k-j];
				f[i&1][j][k]%=mod;
			}
		for (int j=l[i-1];j<=r[i-1];j++)
			memset(f[(i-1)&1][j],0,sizeof(f[(i-1)&1][j]));
	}
	for (int i=0;i<=n;i++)
		for (int j=i;j<=n;j++)
			ans=(ans+f[n&1][i][j]*A[n-i][j-i])%mod;
	cout<<ans<<endl;
	return 0;
}
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf
//zjf