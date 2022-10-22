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
const int N=1e5+2;
bitset<512> ed[N],now;
int a[N],lst[512];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);

	int n,i,j;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) if (a[i])
	{
		ed[i][a[i]]=ed[i][0]=1;now.reset();
		for (j=1;j<a[i];j++) if (lst[j]) now|=ed[lst[j]];
		for (j=1;j<=511;j++) if (now[j]) ed[i][a[i]^j]=1;
		lst[a[i]]=i;
	}
	now.reset();now[0]=1;
	for (i=1;i<=n;i++) now|=ed[i];
	cout<<now.count()<<'\n';
	for (i=0;i<=511;i++) if (now[i]) cout<<i<<' ';
}