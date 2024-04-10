#include <bits/stdc++.h>
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[200001],rev[200001];
int dist[200001],a[200001];
int main() {
	MEM_1(dist);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		rev[y].pb(x);
	}
	int k;
	scanf("%d",&k);
	fup(i,1,k,1)scanf("%d",a+i);
	dist[a[k]]=0;
	queue<int> q;
	q.push(a[k]);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:rev[x])
		{
			if(dist[next]==-1)
			{
				dist[next]=dist[x]+1;
				q.push(next);
			}
		}
	}
	int mn=0,mx=0;
	fup(i,1,k-1,1)
	{
		int x=a[i],y=a[i+1];
		if(dist[x]!=dist[y]+1)mn++,mx++;
		else
		{
			bool ok=0;
			for(int next:v[x])
			{
				if(next==y)continue;
				if(dist[next]==dist[y])ok=1;
			}
			if(ok)mx++;
		}
	}
	printf("%d %d\n",mn,mx);
}