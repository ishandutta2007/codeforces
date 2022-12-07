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
#define INF 98765432198765
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[1000];
bool inter(int l1, int r1, int l2, int r2)
{
	if (l1 == l2 && r1 == r2)return 1;
	if (r1 <= l2)return 0;
	if (r2 <= l1)return 0;
	if (l1 <= l2 &&r1 >= r2)return 0;
	if (l2 <= l1&&r2 >= r1)return 0;
	if (l1 < l2&&l2 < r1&&r1 < r2)return 1;
	if (l2 < r1&&l1 < r2&&r2 < r1)return 1;
	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
		scanf("%d", a + i);
	fup(i, 1, n - 1, 1)
	{
		int l1 = a[i - 1], r1 = a[i];
		if (l1 > r1)swap(l1, r1);
		fup(j, 1, i - 1, 1)
		{
			int l2 = a[j - 1], r2 = a[j];
			if (l2 > r2)swap(l2, r2);
			if (inter(l1, r1, l2, r2))
			{
				return !printf("yes");
			}
		}
	}
	puts("no");
}