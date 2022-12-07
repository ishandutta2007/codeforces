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
#define INF 98765432198765432
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[300005];
bool tree[1100000];
int n,K;
void upd(int node, int S, int E, int k)
{
	if (S == E)
	{
		tree[node]=1;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k);
	tree[node]=tree[node*2]|tree[node*2+1];
}

bool find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) | find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
bool ok(int k)
{
	MEM0(tree);
	Vi v(n+1);
	int r=1;
	fup(l,1,n,1)
		while(r<=n && a[r]-a[l]<=k)v[r++]=l;
	upd(1,0,n,0);
	fup(i,1,n,1)
	{
		bool t=find(1,0,n,v[i]-1,i-K);
		if(t)upd(1,0,n,i);
	}
	return find(1,0,n,n,n);
}
int main() {
	scanf("%d%d",&n,&K);
	fup(i,1,n,1)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int l=0,r=1e9+1;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	printf("%d",l);
}