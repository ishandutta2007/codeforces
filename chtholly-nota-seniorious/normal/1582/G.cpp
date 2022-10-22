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
namespace prm
{
	const int N=1e6+2;
	int ss[N>>2],mn[N];
	int cnt;
	void init()
	{
		int n=N-2;
		for (int i=2;i<=n;i++)
		{
			if (!mn[i]) mn[ss[++cnt]=i]=i;
			for (int j=1;j<=cnt&&i*ss[j]<=n;j++)
			{
				mn[i*ss[j]]=ss[j];
				if (i%ss[j]==0) break;
			}
		}
	}
}
typedef pair<int,int> pa;
using prm::ss;
using prm::mn;
const int N=1e6+2,M=4e6+2;
vector<pa> bel[N];
string B;
int a[N],b[N];
namespace sgt
{
	const int N=1e6+2,M=4e6+2;
	int l[M],r[M],s[M];
	int a[N];
	int n,y,z,val,ans,L;
	void build(int x)
	{
		if (l[x]==r[x]) return s[x]=a[l[x]],void();
		int c=x<<1;
		l[c]=l[x];r[c]=l[x]+r[x]>>1;
		l[c|1]=r[c]+1;r[c|1]=r[x];
		build(c);build(c|1);
		s[x]=min(s[c],s[c|1]);
	}
	void find_in_tree(int x)
	{
		if (s[x]>=val) return;
		if (l[x]==r[x]) {ans=l[x];return;}
		int c=x<<1;
		if (r[c]>=L) find_in_tree(c);
		if (ans==n+1) find_in_tree(c|1);
	}
	int find(int value,int l)
	{
		if (s[1]>=value) return n+1;
		val=value;ans=n+1;L=l;
		find_in_tree(1);
		return ans;
	}
	void init(int nn,int *b)
	{
		r[l[1]=1]=n=nn;
		memcpy(a+1,b+1,n*sizeof a[0]);
		build(1);
	}
};
namespace sgt2
{
	const int N=1e6+2,M=4e6+2;
	int l[M],r[M],lz[M];
	int a[N];
	int n,y,z,val,ans,L;
	void build(int x)
	{
		lz[x]=n;
		if (l[x]==r[x]) return;
		int c=x<<1;
		l[c]=l[x];r[c]=l[x]+r[x]>>1;
		l[c|1]=r[c]+1;r[c|1]=r[x];
		build(c);build(c|1);
	}
	void mdf(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			lz[x]=min(lz[x],val);
			return;
		}
		int c=x<<1;
		if (z<=r[c]) mdf(c);
		if (y>r[c]) mdf(c|1);
	}
	void modify(int l,int r,int v)
	{
		z=l;y=r;val=v;mdf(1);
	}
	void allpd(int x)
	{
		if (l[x]==r[x]) {a[l[x]]=lz[x];return;}
		int c=x<<1;
		if (lz[x]!=n+1)
		{
			lz[c]=min(lz[c],lz[x]);
			lz[c|1]=min(lz[c|1],lz[x]);
			lz[x]=n+1;
		}
		allpd(c);allpd(c|1);
	}
	void init(int nn)
	{
		r[l[1]=1]=n=nn;
		build(1);
	}
};
int n;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);

	int i,j;
	cin>>n;
	prm::init();
	for (i=1;i<=n;i++) cin>>a[i];
	cin>>B;
	for (i=1;i<=n;i++) if (B[i-1]=='*') b[i]=1; else b[i]=-1;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		while (x>1)
		{
			int y=mn[x],z,cnt=1;
			x/=y;
			while ((z=x/y)*y==x) x=z,++cnt;
			bel[y].emplace_back(i,cnt*b[i]);
		}
	}
	sgt2::init(n);
	for (i=1;i<N;i++) if (bel[i].size())
	{
		//cout<<i<<endl;
		static int b[N];
		int m=bel[i].size();
		//for (j=1;j<=m;j++) cout<<bel[i][j-1].second<<" \n"[j==m];
		for (j=1;j<=m;j++) b[j]=b[j-1]+bel[i][j-1].second;
		sgt::init(m,b);
		for (j=1;j<=m;j++)
		{
			int R=sgt::find(b[j-1],j);//cout<<"["<<j<<","<<R<<"]"<<endl;
			if (R<=m) sgt2::modify(j==1?1:bel[i][j-2].first+1,bel[i][j-1].first,bel[i][R-1].first-1);
		}
	}
	sgt2::allpd(1);
	//for (i=1;i<=n;i++) cout<<sgt2::a[i]<<" \n"[i==n];
	ll ans=0;
	for (i=1;i<=n;i++) if (sgt2::a[i]>=i) ans+=sgt2::a[i]-i+1;
	cout<<ans<<endl;
}