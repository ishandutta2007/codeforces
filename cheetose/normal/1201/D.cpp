#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m,k,q;
Pi p[200001];
int b[200005];
ll d[200001][2];
int ne[200001];
ll go(int N,int c)
{
	ll &ret=d[N][c];
	if(ret!=-1)return ret;
	ret=INF;
	int l,r,nn=ne[N];
	tie(l,r)=p[N];
	if(nn>n)return ret=r-l;
	if(c==0)
	{
		int t1=*(upper_bound(b,b+q,r)-1);
		int t2=*lower_bound(b,b+q,r);
		int tt=nn-N+abs(r-t1)+r-l;
		if(t1!=0)ret=min({ret,tt+abs(p[nn].Y-t1)+go(nn,1),tt+abs(t1-p[nn].X)+go(nn,0)});
		tt=nn-N+abs(t2-r)+r-l;
		if(t2<=m)ret=min({ret,tt+abs(p[nn].Y-t2)+go(nn,1),tt+abs(t2-p[nn].X)+go(nn,0)});
	}
	else
	{
		int t1=*(upper_bound(b,b+q,l)-1);
		int t2=*lower_bound(b,b+q,l);
		int tt=nn-N+abs(l-t1)+r-l;
		if(t1!=0)ret=min({ret,tt+abs(p[nn].Y-t1)+go(nn,1),tt+abs(t1-p[nn].X)+go(nn,0)});
		tt=nn-N+abs(t2-l)+r-l;
		if(t2<=m)ret=min({ret,tt+abs(p[nn].Y-t2)+go(nn,1),tt+abs(t2-p[nn].X)+go(nn,0)});
	}
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d%d%d%d",&n,&m,&k,&q);
	fup(i,1,n,1)p[i]=mp(987654321,-1);
	p[1]=mp(1,1);
	fup(i,1,k,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[x].X=min(p[x].X,y);
		p[x].Y=max(p[x].Y,y);
	}
	{
		int t=n+1;
		fdn(i,n,1,1)
		{
			ne[i]=t;
			if(p[i].X!=987654321)t=i;
		}
	}
	fup(i,0,q-1,1)scanf("%d",b+i);
	b[q]=0,b[q+1]=m+1;
	q+=2;
	sort(b,b+q);
	printf("%lld\n",go(1,0));
}