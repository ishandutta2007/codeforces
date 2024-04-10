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
const int MOD = 5000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[2001];
int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	scanf("%s", s);
	bool ok = 0;
	fup(i, 0, p - 1, 1)
	{
		Vi v1,v2,v3;
		fup(j, i, n - 1, p)
		{
			if (s[j] == '.')v1.push_back(j);
			else if (s[j] == '1')v2.push_back(j);
			else v3.push_back(j);
		}
		if (v2.size() && v3.size())
		{
			ok = 1;
			break;
		}
		if (v1.size() > 1)
		{
			s[v1[0]] = '1';
			s[v1[1]] = '0';
			ok = 1;
			break;
		}
		if (v1.size() && v2.size())
		{
			ok = 1;
			s[v1[0]] = '0';
			break;
		}
		if (v1.size() && v3.size())
		{
			ok = 1;
			s[v1[0]] = '1';
			break;
		}
	}
	if (!ok)return !printf("No");
	fup(i, 0, n - 1, 1)
		if (s[i] == '.')s[i] = '0';
	printf("%s", s);
}