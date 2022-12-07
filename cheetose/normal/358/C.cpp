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
#define INF 987654321987654321
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

Vi v;
int tt[100000];
void print()
{
	if (v.empty())
	{
		puts("0");
		return;
	}
	if (v.size() == 1)
	{
		puts("pushStack");
		puts("1 popStack");
		return;
	}
	if (v.size() == 2)
	{
		puts("pushStack");
		puts("pushQueue");
		puts("2 popStack popQueue");
		return;
	}
	if (v.size() == 3)
	{
		puts("pushStack");
		puts("pushQueue");
		puts("pushFront");
		puts("3 popStack popQueue popFront");
		return;
	}
	VPi t;
	int N = v.size();
	fup(i, 0, N - 1, 1)
		t.push_back(mp(v[i], i));
	sort(t.rbegin(), t.rend());
	fup(i, 0, N - 1, 1)
		tt[t[i].Y] = i;
	fup(i, 0, N - 1, 1)
	{
		if (tt[i] == 0)puts("pushStack");
		else if (tt[i] == 1)puts("pushQueue");
		else if (tt[i] == 2)puts("pushFront");
		else puts("pushBack");
	}
	puts("3 popStack popQueue popFront");
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			print();
			v.clear();
		}
		else v.push_back(x);
	}
	while (!v.empty())
	{
		puts("pushStack");
		v.pop_back();
	}
}