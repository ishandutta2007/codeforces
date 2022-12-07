#include <bits/stdc++.h>
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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

struct Node {
	ll lsum, rsum, maxsum, sum;
};
Node tree[262144];
void init(int node,int S,int E)
{
	if(S==E)
	{
		const ll inf=987654321;
		tree[node]={-inf,-inf,-inf,-inf};
		return;
	}
	init(node<<1,S,S+E>>1);
	init(node<<1|1,(S+E>>1)+1,E);
	tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].sum + tree[node * 2 + 1].lsum);
	tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].sum + tree[node * 2].rsum);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxsum = max({ tree[node * 2].maxsum, tree[node * 2 + 1].maxsum, tree[node * 2].rsum + tree[node * 2 + 1].lsum });
}
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
	if (R.rsum == T.lsum)return L;
	T.lsum = max(L.lsum, L.sum + R.lsum);
	T.rsum = max(R.rsum, R.sum + L.rsum);
	T.sum = L.sum + R.sum;
	T.maxsum = max({ L.maxsum, R.maxsum, L.rsum + R.lsum });
	return T;
}

int n,q;
int a[100001],b[100001],L[100000],R[100000];
iii query[100000];
Vi v[100001];
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)b[i]=i;
	sort(b+1,b+n+1,[&](int x,int y){
		return a[x]>a[y];
	});
	scanf("%d",&q);
	fup(i,0,q-1,1)
	{
		int l,r,w;
		scanf("%d%d%d",&l,&r,&w);
		query[i]=iii(l,r,w);
		L[i]=1,R[i]=n;
	}
	bool ok=1;
	while(ok)
	{
		ok=0;
		fup(i,1,n,1)v[i].clear();
		init(1,1,n);
		fup(i, 0, q - 1, 1)
		{
			if (L[i] <= R[i])v[(L[i] + R[i]) / 2].push_back(i);
		}
		fup(i,1,n,1)
		{
			int ii=b[i];
			upd(1,1,n,ii,1);
			while(!v[i].empty())
			{
				ok=1;
				int j=v[i].back();
				v[i].pop_back();
				int l,r,w;
				tie(l,r,w)=query[j];
				ll t=find(1,1,n,l,r).maxsum;
				if(t>=(ll)w)R[j]=i-1;
				else L[j]=i+1;
			}
		}
	}
	fup(i,0,q-1,1)printf("%d\n",a[b[L[i]]]);
}