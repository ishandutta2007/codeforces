#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
const int p=998244353;
const db eps=1e-9;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e6+2,M=1e6+2,inf=1e9;
vector<int> lj[N];
int a[N],b[N],rd[N],dl[N],fc[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks,tou,wei;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		for (i=1;i<=n;i++) lj[i].clear(),rd[i]=rd[j]=0;
		for (i=1;i<n;i++) cin>>x>>y,lj[x].push_back(y),lj[y].push_back(x),++rd[x],++rd[y];
		if (n<=2) {cout<<n*int(m==0)<<'\n';continue;}
		tou=1;wei=0;
		for (i=1;i<=n;i++) if (rd[i]==1) dl[++wei]=i,fc[i]=0;
		while (tou<=wei)
		{
			int u=dl[tou++];
			for (auto v:lj[u]) if (rd[v]!=1)
			{
				if (--rd[v]==1) dl[++wei]=v,fc[v]=fc[u]+1;
			}
		}
		ans=0;
		for (i=1;i<=n;i++) ans+=fc[i]>=m;
		cout<<ans<<'\n';
	}
}