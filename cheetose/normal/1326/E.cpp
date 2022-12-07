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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Pi tree[1048576];
void upd(int node, int S, int E, int k, int t)
{
	if (S == E)
	{
		if(t==1)tree[node].X++;
		else tree[node].Y++;
		if(tree[node].X==1 && tree[node].Y==1)tree[node]=mp(0,0);
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, t);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, t);
	int tt=min(tree[node<<1].X,tree[node<<1|1].Y);
	tree[node].X=tree[node<<1].X+tree[node<<1|1].X-tt;
	tree[node].Y=tree[node<<1].Y+tree[node<<1|1].Y-tt;
}
int a[300003],b[300003],t[300003];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		t[a[i]]=i;
	}
	fup(i,1,n,1)scanf("%d",b+i);
	int ans=n;
	printf("%d ",ans);
	upd(1,1,n,t[ans],1);
	fup(i,1,n-1,1)
	{
		upd(1,1,n,b[i],2);
		while(tree[1].X==0)
		{
			upd(1,1,n,t[--ans],1);
		}
		printf("%d ",ans);
	}
}