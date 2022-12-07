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
#define INF 98765432198765321
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

struct P{
	ll a, b;
	P(){a=0,b=0;}
	P(ll x,ll y){a=x,b=y;}
	P operator +(P p){
		P c;
		c.a=a+p.a;
		c.b=b+p.b;
		return c;
	}
	bool operator >(P &p)
	{
		return a-b>p.a-p.b;
	}
	bool operator <(P &p)
	{
		return b-a>p.b-p.a;
	}
}maxtree[524288],mintree[524288];
P mx(P p1,P p2)
{
	if(p1>p2)return p1;
	else return p2;
}
P mn(P p1,P p2)
{
	if(p1<p2)return p1;
	else return p2;
}

ll s[200005];
P d[200005][2];


void upd(int node, int S, int E, int k)
{
	if (S == E)
	{
		mintree[node]=P(0,s[S-1])+d[S][0];
		maxtree[node]=P(s[S-1],0)+d[S][1];
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k);
	maxtree[node]=mx(maxtree[node*2],maxtree[node*2+1]);
	mintree[node]=mn(mintree[node*2],mintree[node*2+1]);
}

P maxfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return P(-INF,INF);
	if (i <= S && j >= E)return maxtree[node];
	return mx(maxfind(node * 2, S, (S + E) / 2, i, j), maxfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
P minfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return P(INF,-INF);
	if (i <= S && j >= E)return mintree[node];
	return mn(minfind(node * 2, S, (S + E) / 2, i, j), minfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	fill(maxtree,maxtree+524288,P(-INF,INF));
	fill(mintree,mintree+524288,P(INF,-INF));
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%lld",s+i);
		s[i]+=s[i-1];
	}
	d[n+1][0]=d[n+1][1]=P(0,0);
	upd(1,0,n+1,n+1);
	fdn(i,n,1,1)
	{
		d[i][0]=maxfind(1,0,n+1,i+1,n+1);
		d[i][1]=minfind(1,0,n+1,i+1,n+1);
		upd(1,0,n+1,i);
	}
	printf("%lld",d[2][0].a-d[2][0].b);
}