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
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
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
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 1000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[200001];
set<int> S0,S1;
set<int>::iterator it0,it1;
vector<Vi> ans;
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	fup(i, 0, n - 1, 1)
	{
		if (s[i] == '0')S0.insert(i + 1);
		else S1.insert(i + 1);
	}
	while (1)
	{
		if (S0.empty())break;
		Vi v;
		int zero = *S0.begin(), one;
		S0.erase(S0.begin());
		v.push_back(zero);
		while (1)
		{
			it1 = S1.lower_bound(zero);
			if (it1 == S1.end())break;
			one = *it1;
			it0 = S0.lower_bound(one);
			if (it0 == S0.end())break;
			zero = *it0;
			S0.erase(it0);
			S1.erase(it1);
			v.push_back(one);
			v.push_back(zero);
		}
		ans.push_back(v);
	}
	if (!S1.empty())return puts("-1");
	printf("%d\n", ans.size());
	for (auto &p:ans)
	{
		printf("%d ", p.size());
		for (int x : p)printf("%d ", x);
		puts("");
	}
}