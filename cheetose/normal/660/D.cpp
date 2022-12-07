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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pi p[2000];
int zz(int x)
{
	if (x == 0)return 0;
	if (x > 0)return 1;
	return -1;
}
inline ll nC2(int x)
{
	return x*(x - 1) / 2;
}
map<Pi, int> A, B;
map<int,int> C, D;
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)scanf("%d%d", &p[i].X, &p[i].Y);
	fup(i,0,n-1,1)
		fup(j, i+1, n - 1, 1)
	{
		int x1, y1, x2, y2;
		tie(x1, y1) = p[i];
		tie(x2, y2) = p[j];
		if (x1 == x2)D[abs(y2 - y1)]++;
		else if (y1 == y2)C[abs(x2 - x1)]++;
		else if (zz(x1 - x2)*zz(y1 - y2) > 0)
			A[mp(abs(x1 - x2), abs(y1 - y2))]++;
		else
			B[mp(abs(x1 - x2), abs(y1 - y2))]++;
	}
	ll ans = 0;
	for (auto it = A.begin(); it != A.end(); it++)ans += nC2(it->Y);
	for (auto it = B.begin(); it != B.end(); it++)ans += nC2(it->Y);
	for (auto it = C.begin(); it != C.end(); it++)ans += nC2(it->Y);
	for (auto it = D.begin(); it != D.end(); it++)ans += nC2(it->Y);
	printf("%lld", ans/2);
}