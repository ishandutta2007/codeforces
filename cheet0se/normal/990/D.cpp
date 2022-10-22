#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
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
#define INF 987654321
#define PI 3.14159265358979323846264
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 5000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool chk[1001][1001];
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a != 1 && b != 1)return !printf("NO");
	if (a == 1 && b == 1)
	{
		if (n == 2 || n==3)return !printf("NO");
		puts("YES");
		fup(i, 2, n, 1)
			chk[i][i - 1] = chk[i - 1][i] = 1;
		fup(i, 1, n, 1)
		{
			fup(j, 1, n, 1)printf("%d", chk[i][j]);
			puts("");
		}
		return 0;
	}
	puts("YES");
	if (b == 1)
	{
		fup(i, 2, n-a+1, 1)chk[1][i] = chk[i][1] = 1;
	}
	else
	{
		fup(i, 2, n - b + 1, 1)chk[1][i] = chk[i][1] = 1;
		fup(i, 1, n, 1)
			fup(j, 1, n, 1)if (i != j)chk[i][j] = !chk[i][j];
	}
	fup(i, 1, n, 1)
	{
		fup(j, 1, n, 1)printf("%d", chk[i][j]);
		puts("");
	}
}