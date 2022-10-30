#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

void IO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
const int maxn=1e3+10,maxm=2e3+10;

int n,m,r;
int sum[maxm][maxm];
bool mp[maxm][maxm];
int b[maxm],x[maxm],y[maxm];

int inv[maxm],finv[maxm],f[maxm];
void init() //inv,f,finv ll
{
    inv[1] = 1;
    for (int i = 2; i < maxm; i++)
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod; //inv: 
    f[0] = finv[0] = 1;                                //f:     finv:(1/f)
    for (int i = 1; i < maxm; i++)
    {
        f[i] = 1ll*f[i - 1] * i % mod;
        finv[i] = 1ll*finv[i - 1] * inv[i] % mod;
    }
}

int C(int n, int m) //C(n,m)
{
    if (m < 0 || m > n)
        return 0;
    return 1ll*f[n] * finv[n - m] % mod * finv[m] % mod;
}

void getsum()
{
	for(int i=1;i<maxn;i++)
		for(int j=1;j<maxn;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
}
inline int getsum(int x,int y)
{
	int xa=max(1,x-r),ya=max(1,y-r),xb=min(1000,x+r),yb=min(1000,y+r);
	return sum[xb][yb]-sum[xa-1][yb]-sum[xb][ya-1]+sum[xa-1][ya-1];
}


int main()
{
	IO();
	init();
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>b[i];
		mp[x[i]][y[i]]=true;
	}
	getsum();

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+1ll*b[i]*b[i]%mod*(1ll*C(n,m)+mod-C(n-getsum(x[i],y[i]),m))%mod)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int un=getsum(x[i],y[i])+getsum(x[j],y[j]);
			int ax=max(x[i],x[j])-r,ay=max(y[i],y[j])-r,bx=min(x[i],x[j])+r,by=min(y[i],y[j])+r;
			ax=max(1,ax),ay=max(1,ay),bx=min(1000,bx),by=min(1000,by);
			if(ax<=bx&&ay<=by)
				un-=sum[bx][by]-sum[ax-1][by]-sum[bx][ay-1]+sum[ax-1][ay-1];
			ll tem=1ll*C(n,m)+mod-C(n-getsum(x[i],y[i]),m)+mod-C(n-getsum(x[j],y[j]),m)+C(n-un,m);
			tem%=mod;
			ans=(ans+2ll*b[i]%mod*b[j]%mod*tem%mod)%mod;
		}
	}
	cout<<ans<<endl;

}