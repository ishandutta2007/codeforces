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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int tree[1<<20];

void init(int node, int S, int E)
{
	tree[node]=0;
	if (S == E)return;
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
}

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
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int a[300001],b[300001],c1[300001],c2[300001];
deque<int> q[300001];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)c1[i]=c2[i]=0;
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		c1[a[i]]++;
	}
	fup(i,1,n,1)
	{
		scanf("%d",b+i);
		c2[b[i]]++;
	}
	fup(i,1,n,1)if(c1[i]!=c2[i])
	{
		puts("NO");
		return;
	}
	fup(i,1,n,1)q[i].clear();
	fup(i,1,n,1)q[a[i]].pb(i);
	init(1,1,n);
	fup(i,1,n,1)
	{
		int x=b[i];
		int t=find(1,1,n,x+1,n);
		if(t>q[x].front())
		{
			puts("NO");
			return;
		}
		upd(1,1,n,x,q[x].front());
		q[x].pop_front();
	}
	puts("YES");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}