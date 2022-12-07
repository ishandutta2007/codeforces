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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

char s[9][10];
bool fullblock(int z)
{
	int x = z / 3, y = z % 3;
	x *= 3, y *= 3;
	fup(i,0,2,1)
		fup(j, 0, 2, 1)
	{
		if (s[i + x][j + y] == '.')return 0;
	}
	return 1;
}
void fillblock(int z)
{
	int x = z / 3, y = z % 3;
	x *= 3, y *= 3;
	fup(i, 0, 2, 1)
		fup(j, 0, 2, 1)
	{
		if (s[i + x][j + y] == '.')s[i + x][j + y] = '!';
	}
}
int main() {
	fup(i, 0, 2, 1)
	{
		fup(j, 0, 2, 1)
			s[i][j] = getchar();
		getchar();
		fup(j, 3, 5, 1)
			s[i][j] = getchar();
		getchar();
		fup(j, 6, 8, 1)
			s[i][j] = getchar();
		getchar();
	}
	getchar();
	fup(i, 3, 5, 1)
	{
		fup(j, 0, 2, 1)
			s[i][j] = getchar();
		getchar();
		fup(j, 3, 5, 1)
			s[i][j] = getchar();
		getchar();
		fup(j, 6, 8, 1)
			s[i][j] = getchar();
		getchar();
	}
	getchar();
	fup(i, 6, 8, 1)
	{
		fup(j, 0, 2, 1)
			s[i][j] = getchar();
		getchar();
		fup(j, 3, 5, 1)
			s[i][j] = getchar();
		getchar();
		fup(j, 6, 8, 1)
			s[i][j] = getchar();
		getchar();
	}
	int x, y;
	scanf("%d%d", &x, &y);
	x--, y--;
	x %= 3, y %= 3;
	int z = 3 * x + y;
	if (fullblock(z))
	{
		fup(i, 0, 8, 1)
			fillblock(i);
	}
	else
		fillblock(z);
	fup(i, 0, 2, 1)
	{
		fup(j, 0, 2, 1)
			printf("%c", s[i][j]);
		printf(" ");
		fup(j, 3, 5, 1)
			printf("%c", s[i][j]);
		printf(" ");
		fup(j, 6, 8, 1)
			printf("%c", s[i][j]);
		puts("");
	}
	puts("");
	fup(i, 3, 5, 1)
	{
		fup(j, 0, 2, 1)
			printf("%c", s[i][j]);
		printf(" ");
		fup(j, 3, 5, 1)
			printf("%c", s[i][j]);
		printf(" ");
		fup(j, 6, 8, 1)
			printf("%c", s[i][j]);
		puts("");
	}
	puts("");
	fup(i, 6, 8, 1)
	{
		fup(j, 0, 2, 1)
			printf("%c", s[i][j]);
		printf(" ");
		fup(j, 3, 5, 1)
			printf("%c", s[i][j]);
		printf(" ");
		fup(j, 6, 8, 1)
			printf("%c", s[i][j]);
		puts("");
	}
}