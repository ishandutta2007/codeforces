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
#define INF 1987654321987654321
#define PI 3.14159265358979323846264
#define MOD 20091101
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

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";//75
string s2 = "What are you doing while sending \"";//34
string s3 = "\"? Are you busy? Will you send \"";//32
string s4 = "\"?";//2
ll leng[53];
char res(int gen, ll k)
{
	if (gen == 0)
	{
		if (k <= 74)return s[k];
		else return '.';
	}
	if (gen > 53 && k >= 34)
		return res(gen - 1, k - 34);
	if (gen > 0 && k < 34)
		return s2[k];
	ll t = leng[gen-1];
	if (gen > 0 && k >= 34 && k < 34 + t)
		return res(gen - 1, k - 34);
	if (gen > 0 && k >= 34 + t&&k < 66 + t)
		return s3[k - 34 - t];
	if (gen > 0 && k >= 66 + t &&k < 66 + 2 * t)
		return res(gen - 1, k - 66 - t);
	if (gen > 0 && k >= 66 + 2 * t && k < 68 + 2 * t)
		return s4[k - 66 - 2 * t];
	if(gen>0 && k>=68+2*t) return '.';
}
int main() {
	leng[0] = 75;
	fup(i, 1, 52, 1)
		leng[i] = leng[i - 1] * 2 + 68;
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n;
		ll k;
		scanf("%d%I64d", &n, &k);
		if (n <= 52 && k > leng[n])
		{
			printf(".");
			continue;
		}
		k--;
		printf("%c", res(n, k));
	}
}