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

int p[200000],a[200000],pre[200001],d[200000][18],L[200000];
int n,m,q;
Vi v[200001];
int tree[524288];
void upd(int node, int S, int E, int k, int dif)
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
int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return -1;
	if (i <= S && j >= E)return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j),find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	MEM_1(d);
	scanf("%d%d%d",&n,&m,&q);
	fup(i,0,n-1,1)scanf("%d",p+i);
	fup(i,0,n-1,1)
	{
		if(i==0)pre[p[i]]=p[n-1];
		else pre[p[i]]=p[i-1];
	}
	fup(i,0,m-1,1)
	{
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	fdn(i,m-1,0,1)
	{
		int des=pre[a[i]];
		int now=upper_bound(ALL(v[des]),i)-v[des].begin()-1;
		if(now!=-1)now=v[des][now];
		d[i][0]=now;
	}
	fup(j,0,16,1)
	{
		fup(i,0,m-1,1)
		{
			if(d[i][j]!=-1)
			{
				d[i][j+1]=d[d[i][j]][j];
			}
		}
	}
	fup(i,0,m-1,1)
	{
		int t=n-1;
		int now=i;
		fdn(k,17,0,1)
		{
			if(now==-1)break;
			if(t&(1<<k))
			{
				now=d[now][k];
				t-=(1<<k);
			}
		}
		L[i]=now;
		upd(1,0,m-1,i,L[i]);
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		if(find(1,0,m-1,l,r)<l)putchar('0');
		else putchar('1');
	}
}