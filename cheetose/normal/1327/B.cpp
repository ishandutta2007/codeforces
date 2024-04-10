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

Vi v[100001];
bool a[100001],b[100001];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)v[i].clear();
	fup(i,1,n,1)a[i]=b[i]=0;
	fup(i,1,n,1)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			v[i].pb(x);
		}
	}
	int match=0;
	fup(i,1,n,1)
	{
		for(int j:v[i])
		{
			if(!b[j])
			{
				a[i]=j,b[j]=1;
				match++;
				break;
			}
		}
	}
	if(match==n)
	{
		puts("OPTIMAL");
		return;
	}
	puts("IMPROVE");
	int t1,t2;
	fup(i,1,n,1)
	{
		if(!a[i])t1=i;
		if(!b[i])t2=i;
	}
	printf("%d %d\n",t1,t2);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}