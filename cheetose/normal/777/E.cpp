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
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct A{
	int a,b,h;
}a[100001];
int cc;
Vi vv;
ll tree[524288];

void upd(int node, int S, int E, int k, ll dif)
{
	if (S == E)
	{
		tree[node]=dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return -INF;
	if (i <= S && j >= E)return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].h);
		vv.pb(a[i].a);
		vv.pb(a[i].b);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,n-1,1)
	{
		a[i].a=lower_bound(ALL(vv),a[i].a)-vv.begin()+1;
		a[i].b=lower_bound(ALL(vv),a[i].b)-vv.begin()+1;
	}
	sort(a,a+n,[&](A a1,A a2){
		if(a1.b==a2.b)return a1.a>a2.a;
		return a1.b>a2.b;
	});
	fup(i,0,n-1,1)
	{
		int aa=a[i].a,bb=a[i].b,hh=a[i].h;
		ll t=find(1,0,N,0,bb-1);
		upd(1,0,N,aa,t+hh);
	}
	printf("%lld",find(1,0,N,0,N));
}