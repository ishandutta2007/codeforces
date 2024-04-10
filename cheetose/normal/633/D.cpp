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
#define INF 98765
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

int a[1000];
bool chk[1000];
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	fup(i, 0, n - 1, 1)
	{
		scanf("%d", a + i);
		if (a[i] == 0)ans++;
	}
	ans = max(ans, 2);
	stack<int> st;
	sort(a, a + n);
	fup(i, 0, n - 1, 1)
		fup(j, 0, n - 1, 1)
	{
		if (i == j || (a[i] == 0 && a[j] == 0))continue;
		int f = a[i], s = a[j], t = 2;
		st.push(i);
		st.push(j);
		chk[i] = chk[j] = 1;
		while (1)
		{
			int l = 0, r = n - 1;
			while (l <= r)
			{
				int m = (l + r) >> 1;
				if (a[m] < f + s)l = m + 1;
				else if (a[m] > f + s)r = m - 1;
				else if (chk[m])l = m + 1;
				else r = m - 1;
			}
			if (l == n || a[l] != f + s)break;
			t++;
			chk[l] = 1;
			st.push(l);
			swap(f, s);
			s += f;
		}
		ans = max(ans, t);
		while (!st.empty())
		{
			chk[st.top()] = 0;
			st.pop();
		}
	}
	printf("%d", ans);
}