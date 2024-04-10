#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=52;
ui *f[N],F[N][N*N*2],*g[N],G[N][N*N*2];
ui p;
void inc(ui &x,ui y){if ((x+=y)>=p) x-=p;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,l;
	cin>>n>>p;
	for (i=0;i<=n;i++) f[i]=F[i]+N*N;
	for (i=0;i<=n;i++) g[i]=G[i]+N*N;
	f[0][0]=1;
	for (i=1;i<=n;i++) for (j=-n*(n-1)/2;j<=n*(n-1)>>1;j++)
	{
		f[i][j]=(ll)f[i-1][j]*i%p;
		g[i][j]=(ll)g[i-1][j]*i%p;
		for (k=1;k<i;k++) f[i][j]=(f[i][j]+(ll)(f[i-1][j+k]+g[i-1][j+k])*(i-k))%p;
		for (k=1;k<i;k++) g[i][j]=(g[i][j]+(ll)(f[i-1][j-k]+g[i-1][j-k])*(i-k))%p;
	}
	ui ans=0;
	for (i=1;i<=n*(n-1)>>1;i++) inc(ans,f[n][i]);
	cout<<ans<<endl;
}