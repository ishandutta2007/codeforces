#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define all(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	ull x=rnd();
	x=x<<32|rnd();
	return x%n+1;
}
#define rand fst
const int p=998244353;
inline void inc(int &x,const int y){if((x+=y)>=p)x-=p;}
inline void dec(int &x,const int y){if((x-=y)<0)x+=p;}
inline int ksm(int x,int y)
{int r=1;while (y){if(y&1)r=(ll)r*x%p;x=(ll)x*x%p;y>>=1;}return r;}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int>> ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(){}
	Q(int a,int b):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e5+2,M=450;
const ll inf=1e18;
ll s[N],f[M],g[N][M];
int a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);

	int T;
	cin>>T;
	while (T--)
	{
		int n,i,j;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		reverse(a+1,a+n+1);
		for (i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		memset(g[0],-1,sizeof g[0]);
		g[0][0]=inf;
		for (i=1;i<=n;i++)
		{
			memset(f,-1,sizeof f);
			int lim=min(M-1,i);
			for (j=1;j<=lim;j++) if (s[i]-s[i-j]<g[i-j][j-1]) f[j]=s[i]-s[i-j];
			for (j=0;j<M;j++) g[i][j]=max(f[j],g[i-1][j]);
		}
		int ans=0;
		for (j=M-1;~j;j--) if (g[n][j]!=-1) break;
		assert(j>=0);cout<<j<<'\n';
	}
}