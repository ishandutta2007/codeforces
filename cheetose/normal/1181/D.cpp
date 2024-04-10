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
typedef vector<db> Vd;
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
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Pll query[500000];
int cnt[500001],ans[500001],cc,c2;
Vi v[500001];
ll sum[500001];
int tree[1050000];
void upd(int node, int S, int E, int k, int dif)
{
	tree[node] += dif;
	if (S == E)return;
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
}
int findK(int node, int S, int E, int k)
{
	if (S == E)return S;
	if (k <= tree[node * 2])return findK(node * 2, S, (S + E) / 2, k);
	return findK(node * 2 + 1, (S + E) / 2 + 1, E, k - tree[node * 2]);
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	fup(i,1,n,1){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	fup(i,1,m,1){
		v[cnt[i]].pb(i);
	}
	fup(i,0,n,1){
		cc+=v[i].size(),c2+=v[i].size()*i;
		sum[i]=1LL*cc*i-c2;
	}
	fup(i,0,q-1,1){
		scanf("%lld",&query[i].X);
		query[i].X-=n;
		query[i].Y=i;
	}
	sort(query,query+q);
	int i=0;
	fup(k,0,q-1,1){
		while(i<=n && query[k].X>sum[i]){
			for(int x:v[i])upd(1,1,m,x,1);
			i++;
		}
		ll t=query[k].X-sum[i-1];
		int now=tree[1];
		int s=(t-1)%now+1;
		ans[query[k].Y]=findK(1,1,m,s);
	}
	fup(i,0,q-1,1)printf("%d\n",ans[i]);
}