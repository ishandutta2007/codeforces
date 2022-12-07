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

char s[50][51];
char cc[5];
int aa[4];
void fil(char A, char B, char C, char D)
{
	int a = aa[0], b = aa[1], c = aa[2], d = aa[3];
	a--;
	fup(i, 0, 49, 1)
		s[0][i] = s[49][i] = s[i][0] = s[i][49] = A;
	int x = 2, y = 2;
	while (a--)
	{
		s[x][y] = A;
		fup(i, 0, 7, 1)
			s[x + ddx[i]][y + ddy[i]] = B;
		b--;
		x += 4;
		if (x > 47)
		{
			x = 2;
			y += 4;
		}
	}
	x = 1, y = 48;
	while (d--)
	{
		s[x][y] = D;
		x += 3;
		if (x > 48)
		{
			y -= 2;
			x = 1;
		}
	}
	x = 2, y = 48;
	while (c--)
	{
		s[x][y] = C;
		x += 3;
		if (x > 48)
		{
			y -= 2;
			x = 2;
		}
	}
	x = 3, y = 48;
	while (b--)
	{
		s[x][y] = B;
		x += 3;
		if (x > 48)
		{
			y -= 2;
			x = 3;
		}
	}
	fup(i, 0, 49, 1)fup(j, 0, 49, 1)if (s[i][j] == '.')s[i][j] = A;
}
int main() {
	fup(i, 0, 49, 1)fup(j, 0, 49, 1)s[i][j] = '.';
	fup(i, 0, 3, 1)
	{
		scanf("%d", aa + i);
		cc[i] = 'A' + i;
	}
	fup(i,0,3,1)
		fup(j, i + 1, 3, 1)
	{
		if (aa[i] > aa[j])
		{
			swap(aa[i], aa[j]);
			swap(cc[i], cc[j]);
		}
	}
	puts("50 50");
	fil(cc[0], cc[1], cc[2], cc[3]);
	fup(i, 0, 49, 1)printf("%s\n", s[i]);
}