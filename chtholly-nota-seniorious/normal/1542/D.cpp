#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=510,p=998244353;
int f[N][N];
int a[N],b[N];
void inc(int &x,int y){if ((x+=y)>=p) x-=p;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		char c;cin>>c;
		if (c=='-') continue;
		cin>>a[i];
	}
	int r=0;
	for (k=1;k<=n;k++) if (a[k])
	{
		int rr=0;
		for (i=1;i<=n;i++) memset(f[i],0,sizeof f[i]);
		f[0][0]=1;
		for (i=1;i<=n;i++) for (j=(i>k);j<=i;j++)
		{
			if (i!=k) f[i][j]=f[i-1][j];
			if (a[i]==0)
			{
				inc(f[i][j],f[i-1][j+1]);
				if (!j) inc(f[i][j],f[i-1][j]);
				continue;
			}
			if (j&&(a[i]<a[k]||a[i]==a[k]&&i<=k))
			{
				inc(f[i][j],f[i-1][j-1]);
			}
			if (a[i]>a[k]||a[i]==a[k]&&i>k) inc(f[i][j],f[i-1][j]);
		}
		// for (i=1;i<=n;i++) for (j=0;j<=i;j++) cout<<f[i][j]<<" \n"[j==i];
		// cout<<endl;
		for (i=1;i<=n;i++) if ((rr+=f[n][i])>=p) rr-=p;
		r=(r+(ll)rr*a[k])%p;
	}
	cout<<r<<endl;
}