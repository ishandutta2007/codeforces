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

int a[200000];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	fup(i, 0, k - 1, 1)scanf("%d", a + i);
	stack<Pi> st;
	st.push(Pi(1, n));
	fup(i, 0, k - 1, 1)
	{
		while (!st.empty() && st.top().X > st.top().Y)st.pop();
		Pi p = st.top();
		st.pop();
		int x = a[i];
		if (x<p.X || x>p.Y)
		{
			puts("-1");
			return 0;
		}
		st.push(Pi(x + 1, p.Y));
		st.push(Pi(p.X, x - 1));
	}
	fup(i, 0, k - 1, 1)printf("%d ", a[i]);
	while (!st.empty())
	{
		Pi p = st.top();
		st.pop();
		fdn(i, p.Y, p.X, 1)
			printf("%d ", i);
	}
}