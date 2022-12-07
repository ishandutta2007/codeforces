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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

VPi m[10005],l[10005];
Vi v[10005];
int tree[10005];
int n;
void upd(int i, int k)
{
	while (i <= 10001)
	{
		tree[i] += k;
		i += (i&-i);
	}
}
int sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1+=5001,x2+=5001,y1+=5001,y2+=5001;
		if(x1==x2)l[x1].pb(mp(min(y1,y2),max(y1,y2)));
		else m[y1].pb(mp(min(x1,x2),max(x1,x2)));
	}
	ll ans=0;
	fup(y,1,10001,1)
	{
		for(Pi p:m[y])
		{
			fup(i,1,10001,1)v[i].clear();
			MEM0(tree);
			fup(x,p.X,p.Y,1)
			{
				for(Pi p2:l[x])
				{
					if(p2.X<=y&&p2.Y>y)
					{
						v[p2.Y].pb(x);
						upd(x,1);
					}
				}
			}
			fup(y2,y+1,10001,1)
			{
				for(Pi p2:m[y2])
				{
					int t=sum(p2.Y)-sum(p2.X-1);
					ans+=t*(t-1)/2;
				}
				for(int x:v[y2])upd(x,-1);
			}
		}
	}
	printf("%lld",ans);
}