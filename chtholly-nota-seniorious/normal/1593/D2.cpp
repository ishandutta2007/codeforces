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
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=4e6+20,M=2e6+10,inf=1e9;
char s[N];
int a[40];
int cnt[N],ss[N],mn[N];
int T,n,m,q,i,j,k,x,y,z,ans,la,ksiz,ks,gs;
vector<int> A;
bool ed[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;n=2e6;
	cin>>T;
	while (T--)
	{
		A.clear();
		cin>>n;m=2e6+2;q=n>>1;
		for (i=0;i<n;i++) cin>>a[i];
		for (i=0;i<n;i++) ++cnt[a[i]+m];
		for (i=0;i<n;i++) if (cnt[a[i]+m]>=q) {q=0; break;}
		for (i=0;i<n;i++) cnt[a[i]+m]=0;
		if (!q)
		{
			cout<<"-1\n";continue;
		}
		for (i=0;i<n;i++) for (j=i+1;j<n;j++)
		{
			x=abs(a[i]-a[j]);
			for (k=1;k*k<=x;k++) if (x%k==0) ed[k]=ed[x/k]=1;
		}
		bool fg=0;
		for (i=m;i;i--) if (ed[i])
		{
			for (j=0;j<n;j++) if (++cnt[(a[j]%i+i)%i]>=q) break;
			if (j<n) q=0;
			for (j=0;j<n;j++) cnt[(a[j]%i+i)%i]=0;
			if (!q) {cout<<i<<'\n'; fg=1;break;}
		}assert(fg);
	}
}