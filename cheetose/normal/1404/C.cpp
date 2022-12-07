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
//typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
//typedef vector<db> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[300001],b[300001],t[300001];
Vi vv[300001];
int tree[300005];
int n,m;
void upd(int i, int k)
{
	while (i <= n)
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

Vi Tree[1048576];
void init(int node, int S, int E)
{
	if (S == E)
	{
		Tree[node].push_back(t[S]);
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	int i = 0, j = 0, n = Tree[2 * node].size(), m = Tree[2 * node + 1].size();
	while (1)
	{
		if (i == n && j == m)break;
		if (i == n) Tree[node].push_back(Tree[2 * node + 1][j++]);
		else if(j==m)Tree[node].push_back(Tree[2 * node][i++]); 
		else if(Tree[2 * node][i] > Tree[2 * node + 1][j]) Tree[node].push_back(Tree[2 * node + 1][j++]);
		else Tree[node].push_back(Tree[2 * node][i++]);
	}
}
int find(int node, int S, int E, int i,int j, int k)
{
	if (i > E || j < S) return 0;
	if (S == E)
	{
		if (t[S] > k)return 1;
		else return 0;
	}
	if (j >= E && i <= S) return Tree[node].end() - upper_bound(Tree[node].begin(), Tree[node].end(), k);
	return find(2 * node, S, (S + E) / 2, i, j, k) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j, k);
}
int main(){
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i);
	fdn(i,n,1,1){
		b[i]=i-a[i];
		if(b[i]>=0)vv[b[i]].pb(i);
	}
	for(int x:vv[0]){
		t[x]=x;
		upd(x,1);
	}
	fup(i,1,n,1){
		if(b[i]<=0)continue;
		int l=1,r=i-1;
		while(l<=r){
			int m=l+r>>1;
			if(sum(i)-sum(m-1)>=b[i])l=m+1;
			else r=m-1;
		}
		t[i]=r;
		if(r>0)upd(r,1);
	}
	init(1,1,n);
	fup(i,0,m-1,1){
		int l,r;
		scanf("%d%d",&l,&r);
		l=l+1,r=n-r;
		printf("%d\n", find(1, 1, n, l,r,l-1));
	}
}