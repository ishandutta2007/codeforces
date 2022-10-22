#pragma GCC optimize("Ofast")
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
const int N=1e6+2,M=1e6+2,inf=1e9;
char s[N];
int bel[N],ans[N],dl[N*2];
int T,n,m,c,i,j,k,x,y,z,ksiz,ks,tou,wei;
struct Q
{
	int z,y,wz;
	Q(int a=0,int b=0,int c=0):z(a),y(b),wz(c){}
	bool operator<(const Q &o) const
	{
		if (bel[z]!=bel[o.z]) return bel[z]<bel[o.z];
		if (bel[z]&1) return y<o.y;
		return y>o.y;
	}
};
void hins(int x)
{
	if (tou<=wei&&dl[tou]==x) ++tou; else dl[--tou]=x;
}
void tins(int x)
{
	if (tou<=wei&&dl[wei]==x) --wei; else dl[++wei]=x;
}
Q a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	cin>>T;
	while (T--)
	{
		cin>>s+1;
		n=strlen(s+1);
		for (i=1;i<=n;i++) s[i]=s[i]=='('||s[i]==')';
		cin>>m;ksiz=n/sqrt(max(m,1));ksiz=max(ksiz,1);ksiz=min(ksiz,n);
		for (i=1;i<=n;i++) bel[i]=(i-1)/ksiz+1;
		for (i=1;i<=m;i++)
		{
			cin>>a[i].z>>a[i].y;
			a[i].wz=i;
		}
		sort(a+1,a+m+1);
		int l=a[1].z,r=l-1;tou=N;wei=N-1;
		for (i=1;i<=m;i++)
		{
			while (l>a[i].z) hins(s[--l]);
			while (r<a[i].y) tins(s[++r]);
			while (l<a[i].z) hins(s[l++]);
			while (r>a[i].y) tins(s[r--]);
			//cout<<a[i].z<<' '<<a[i].y<<'\n';
			//for (j=tou;j<=wei;j++) cout<<dl[j]<<' ';cout<<endl;
			ans[a[i].wz]=wei-tou+1;
		}
		for (i=1;i<=m;i++) cout<<ans[i]/2<<'\n';
	}
}