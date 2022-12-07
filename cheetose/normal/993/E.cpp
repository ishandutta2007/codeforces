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

int a[200001], sum[200001];
ll cnt[200001];
void fft(vector <base> &a, bool invert)
{
	int n = a.size();
	for (int i = 1, j = 0; i<n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len*(invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; j++) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (int i = 0; i<n; i++) a[i] /= n;
	}
}
void multiply(const vector<ll> &a, const vector<ll> &b, vector<ll> &res)
{
	vector <base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size())) n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for (int i = 0; i<n; i++) fa[i] *= fb[i];
	fft(fa, true);
	res.resize(n);
	for (int i = 0; i<n; i++) res[i] = ll(fa[i].real() + (fa[i].real()>0 ? 0.5 : -0.5));
}
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	cnt[0] = 1;
	fup(i, 1, n, 1)
	{
		int xx;
		scanf("%d", &xx);
		if (xx < x)a[i] = 1;
		else a[i] = 0;
		sum[i] = sum[i - 1] + a[i];
		cnt[sum[i]]++;
	}
	ll zero = 0;
	fup(i, 0, n, 1)zero += cnt[i] * (cnt[i] - 1) / 2;
	Vll A, B, C;
	A.resize(3 * n), B.resize(3 * n);
	fup(i, 0, n, 1)A[i] = cnt[i];
	fup(i, 0, n, 1)B[i] = cnt[n - i];
	multiply(A, B, C);
	printf("%lld ", zero);
	fup(i, n+1, 2 * n, 1)printf("%lld ", C[i]);
}