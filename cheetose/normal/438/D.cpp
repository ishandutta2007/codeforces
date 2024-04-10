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
#define INF 1987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll sum[262144],mx[262144];
ll a[100001];
void init(int node,int S,int E)
{
	if(S==E)
	{
		sum[node]=mx[node]=a[S];
		return;
	}
	init(node*2,S,(S+E)/2);
	init(node*2+1,(S+E)/2+1,E);
	sum[node]=sum[node*2]+sum[node*2+1];
	mx[node]=max(mx[node*2],mx[node*2+1]);
}
void upd(int node, int S, int E, int k, ll dif)
{
	if (S == E)
	{
		mx[node]=sum[node]=dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	sum[node]=sum[node*2]+sum[node*2+1];
	mx[node]=max(mx[node*2],mx[node*2+1]);
}
void upd(int node,int S,int E,int l,int r,int m)
{
	l=max(S,l),r=min(r,E);
	if(l>r)return;
	if(S==l && E==r && mx[node]<m)return;
	if(S==E)
	{
		sum[node]%=m;
		mx[node]=sum[node];
		return;
	}
	upd(node*2,S,(S+E)/2,l,r,m);
	upd(node*2+1,(S+E)/2+1,E,l,r,m);
	sum[node]=sum[node*2]+sum[node*2+1];
	mx[node]=max(mx[node*2],mx[node*2+1]);
}

ll find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return sum[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,1,n,1)scanf("%lld",a+i);
	init(1,1,n);
	while(q--)
	{
		int o;
		scanf("%d",&o);
		int l,r,m;
		if(o==1)
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",find(1,1,n,l,r));
		}
		else if(o==2)
		{
			scanf("%d%d%d",&l,&r,&m);
			upd(1,1,n,l,r,m);
		}
		else
		{
			scanf("%d%d",&l,&m);
			upd(1,1,n,l,m);
		}
	}
}