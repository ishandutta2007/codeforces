#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

map<int, int> M;
map<int, int>::iterator it,it2;
int main() {
	int n,q;
	scanf("%d%d", &n,&q);
	M[0] = 0;
	M[MOD] = MOD;
	M[1] = n;
	int ans = n;
	while (q--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		if (k == 1)
		{
			it = M.upper_bound(r);
			it--;
			while (it!=M.begin())
			{
				it2 = it;
				it--;
				int L = it2->X, R = it2->Y;
				if (l <= R)
				{
					M.erase(it2);
					ans -= R - L + 1;
				}
				if (L <= r && R > r)
				{
					M[r + 1] = R;
					ans += R - r;
				}
				if (L < l && R >= l)
				{
					M[L] = l - 1;
					ans += l - L;
				}
				if (L <= l)break;
			}
		}
		else
		{
			it = M.upper_bound(r);
			it--;
			int L = MOD, R = -1;
			while (it != M.begin())
			{
				it2 = it;
				it--;
				if (it2->Y < l)break;
				L = min(L,it2->X), R = max(R,it2->Y);
				ans -= it2->Y - it2->X + 1;
				M.erase(it2);
			}
			M[min(l, L)] = max(r, R);
			ans += max(r, R) - min(l, L) + 1;
		}
		printf("%d\n", ans);
	}
}