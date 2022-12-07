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
#define INF 987654321
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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct fraction {
	ll a, b;
	fraction(ll A, ll B) { a = A, b = B; }
	fraction() { fraction(0, 1); }
	bool operator <= (const fraction &O) const
	{
		ll A = O.a, B = O.b;
		return a*B <= b*A;
	}
	bool operator >= (const fraction &O)const
	{
		ll A = O.a, B = O.b;
		return a*B >= b*A;
	}
	bool operator < (const fraction &O)const
	{
		ll A = O.a, B = O.b;
		return a*B < b*A;
	}
	bool operator > (const fraction &O)const
	{
		ll A = O.a, B = O.b;
		return a*B > b*A;
	}
};
typedef pair<fraction,int> P;
Vi v[100001];
int good[100001],tot[100001],val[100001],cc;
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,k-1,1)
	{
		int x;
		scanf("%d",&x);
		val[x]=-1;
	}
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,1,n,1)
	{
		tot[i]+=v[i].size(),good[i]+=v[i].size();
		if(val[i])for(int x:v[i])good[x]--;
	}
	priority_queue<P, vector<P>, greater<P> > q;
	fup(i,1,n,1)
	{
		if(!val[i])q.push(P(fraction(good[i],tot[i]),i));
	}
	fraction best(0,1);
	int res=0;
	while(!q.empty())
	{
		int i=q.top().Y;
		fraction f=q.top().X;
		q.pop();
		if(val[i])continue;
		val[i]=++cc;
		if(f>=best)
		{
			best=f;
			res=cc;
		}
		for(int x:v[i])
		{
			good[x]--;
			if(!val[x]) q.push(P(fraction(good[x], tot[x]), x));
		}
	}
	printf("%d\n",cc-res+1);
	fup(i,1,n,1)if(val[i]>=res)printf("%d ",i);
}