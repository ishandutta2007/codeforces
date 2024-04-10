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
#define INF 1987654321987654321
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

Vll vv;

int o[100000];
ll l[100000],r[100000];
int tree[2097152],lazy[2097152];
bool inv[2097152];
void propagation(int node,int S,int E)
{
	if(inv[node])
	{
		tree[node]=(E-S+1)-tree[node];
		if(S!=E)
		{
			if(lazy[node*2]!=-1)
			{
				inv[node*2]=0;
				lazy[node*2]^=1;
			}
			else inv[node*2]^=1;
			if(lazy[node*2+1]!=-1)
			{
				inv[node*2+1]=0;
				lazy[node*2+1]^=1;
			}
			else inv[node*2+1]^=1;
		}
		inv[node]=0;
	}
	if(lazy[node]!=-1)
	{
		tree[node]=lazy[node]*(E-S+1);
		if(S!=E)
		{
			lazy[node*2]=lazy[node];
			inv[node*2]=0;
			lazy[node*2+1]=lazy[node];
			inv[node*2+1]=0;
		}
		lazy[node]=-1;
	}
}
void upd1(int node,int S,int E,int i,int j,int val)
{
	propagation(node,S,E);
	if(j<S || i>E)return;
	if(j>=E && i<=S)
	{
		lazy[node]=val;
		propagation(node,S,E);
		return;
	}
	upd1(node*2,S,(S+E)/2,i,j,val);
	upd1(node*2+1,(S+E)/2+1,E,i,j,val);
	tree[node]=tree[node*2]+tree[node*2+1];
}
void upd2(int node,int S,int E,int i,int j)
{
	propagation(node,S,E);
	if(j<S || i>E)return;
	if(j>=E && i<=S)
	{
		inv[node]=1;
		propagation(node,S,E);
		return;
	}
	upd2(node*2,S,(S+E)/2,i,j);
	upd2(node*2+1,(S+E)/2+1,E,i,j);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int find(int node,int S,int E)
{
	propagation(node, S, E);
	if(S==E)return S;
	int M=(S+E)/2;
	propagation(node*2,S,M);
	propagation(node*2+1,M+1,E);
	if(tree[2*node]<M-S+1)return find(node*2,S,M);
	return find(node*2+1,M+1,E);
}
int main() {
	int n;
	scanf("%d",&n);
	vv.pb(1);
	fup(i,0,n-1,1)
	{
		scanf("%d%lld%lld",o+i,l+i,r+i);
		fup(kk,-1,1,1)
		{
			if(l[i]+kk>0)vv.pb(l[i]+kk);
			if(r[i]+kk>0)vv.pb(r[i]+kk);
		}
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,n-1,1)
	{
		l[i]=lower_bound(ALL(vv),l[i])-vv.begin();
		r[i]=lower_bound(ALL(vv),r[i])-vv.begin();
		if(o[i]==1) upd1(1,0,N-1,l[i],r[i],1);
		else if(o[i]==2) upd1(1,0,N-1,l[i],r[i],0);
		else upd2(1,0,N-1,l[i],r[i]);
		printf("%lld\n",vv[find(1,0,N-1)]);
	}
}