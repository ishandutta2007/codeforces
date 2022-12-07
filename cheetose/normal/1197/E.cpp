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

Pi tree[524288];
Pi mn(Pi p1,Pi p2)
{
	if(p1.X<p2.X)return p1;
	if(p1.X>p2.X)return p2;
	return Pi(p1.X,(p1.Y+p2.Y)%MOD);
}
void upd(int node, int S, int E, int k, Pi dif)
{
	if (S == E)
	{
		tree[node]=dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=mn(tree[node*2],tree[node*2+1]);
}

Pi find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return mp(INF+INF,0);
	if (i <= S && j >= E)return tree[node];
	return mn(find(node * 2, S, (S + E) / 2, i, j),find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int n;
Pi p[200000];
int main() {
	fill(tree,tree+524288,mp(INF+INF,0));
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d%d",&p[i].Y,&p[i].X);
	sort(p,p+n);
	fdn(i,n-1,0,1)
	{
		int t=lower_bound(p,p+n,mp(p[i].Y,-1))-p;
		if(t==n)
		{
			upd(1,0,n-1,i,mp(p[i].X,1));
			continue;
		}
		Pi tt=find(1,0,n-1,t,n-1);
		upd(1,0,n-1,i,mp(tt.X+p[i].X-p[i].Y,tt.Y));
	}
	printf("%d\n",find(1,0,n-1,0,n-1).Y);
}