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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[1000005];
int a[1000005];
int S[1000005],E[1000005] ,cc;
void dfs(int N)
{
	S[N]=++cc;
	for(int next:v[N])dfs(next);
	E[N]=++cc;
}
struct Node {
	ll lsum, rsum, maxsum, sum;
};
Node tree[2097152<<1];
void upd(int node, int S, int E, int i, ll k)
{
	if (S == E)
	{
		tree[node].lsum = k;
		tree[node].rsum = k;
		tree[node].maxsum = k;
		tree[node].sum = k;
		return;
	}
	if (i <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, i, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, i, k);
	tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].sum + tree[node * 2 + 1].lsum);
	tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].sum + tree[node * 2].rsum);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxsum = max({ tree[node * 2].maxsum, tree[node * 2 + 1].maxsum, tree[node * 2].rsum + tree[node * 2 + 1].lsum });
}
Node find(int node, int S, int E, int i, int j)
{
	Node T = { -INF,-INF,-INF,-INF };
	if (i > E || j < S)return T;
	if (i <= S && j >= E)return tree[node];
	Node L = find(node * 2, S, (S + E) / 2, i, j);
	Node R = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if (L.lsum == T.lsum)return R;
	if (R.lsum == T.lsum)return L;
	T.lsum = max(L.lsum, L.sum + R.lsum);
	T.rsum = max(R.rsum, R.sum + L.rsum);
	T.sum = L.sum + R.sum;
	T.maxsum = max({ L.maxsum, R.maxsum, L.rsum + R.lsum });
	return T;
}
int main() {
	fup(i,1,2097151,1)tree[i]={-INF,-INF,-INF,-INF};
	int n,k;
	scanf("%d%d",&n, &k);
	fup(i,1,n,1)scanf("%d",a+i);
	stack<Pi> st;
	st.push(mp(n+1,n+1));
	fdn(i,n,1,1)
	{
		while(st.top().X<=a[i])st.pop();
		v[st.top().Y].pb(i);
		st.push(mp(a[i],i));
	}
	n++;
	dfs(n);
	fup(i,1,k-1,1)
	{
		upd(1,1,2*n,S[i],1);
		upd(1,1,2*n,E[i],-1);
	}
	fup(i,k,n-1,1)
	{
		upd(1,1,2*n,S[i],1);
		upd(1,1,2*n,E[i],-1);
		printf("%lld ",tree[1].maxsum);
		upd(1,1,2*n,S[i-k+1],-INF);
		upd(1,1,2*n,E[i-k+1],-INF);
	}
}