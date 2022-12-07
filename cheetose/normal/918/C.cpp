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
#define MOD 1000000007LL
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
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return gcd(a, b); return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[5001];
bool d[5000][5000];
int main() {
	scanf("%s", s);
	int n = strlen(s);
	int ans = 0;
	fup(i, 0, n - 1, 1)
	{
		if (s[i] == ')')continue;
		int c1 = 0, c2 = 0, c3 = 0;
		fup(j, i, n - 1, 1)
		{
			if (j == i)c1++;
			else
			{
				if (s[j] == '(')c1++;
				else if (s[j] == ')')c2++;
				else c3++;
			}
			if (c1 + c3 < c2)break;
			if ((j - i) % 2 == 0 || s[j]=='(')continue;
			if (c2 + c3 >= c1 && c1 + c3 >= c2)
			{
				d[i][j] = 1;
			}
		}
	}
	fdn(j, n-1, 0, 1)
	{
		if (s[j] == '(')continue;
		int c1 = 0, c2 = 0, c3 = 0;
		fdn(i, j, 0, 1)
		{
			if (j == i)c1++;
			else
			{
				if (s[i] == ')')c1++;
				else if (s[i] == '(')c2++;
				else c3++;
			}
			if (c1 + c3 < c2)
			{
				fdn(k,i,0,1)
					d[k][j] = 0;
				break;
			}
			if ((j - i) % 2 == 0)continue;
		}
	}
	fup(i, 0, n - 1, 1)
		fup(j, 0, n - 1, 1)
	{
		if (d[i][j])
		{
			ans++;
		}
	}
	printf("%d", ans);
}