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

bool pos[26];
char s[100001];
int main() {
	fill(pos, pos + 26, true);
	bool finish = 0;
	int ans = 0;
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		char temp[2];
		scanf("%s %s", temp, s);
		if (temp[0] == '!')
		{
			bool chk[26] = { 0 };
			for (int ii = 0; s[ii]; ii++)
				chk[s[ii] - 'a'] = 1;
			fup(ii, 0, 25, 1)
			{
				if (!chk[ii])pos[ii] = 0;
			}
			if (finish)ans++;
		}
		else if (temp[0] == '?')
		{
			pos[s[0] - 'a'] = 0;
			if (i!=n-1 && finish)ans++;
		}
		else
		{
			bool chk[26] = { 0 };
			for (int ii = 0; s[ii]; ii++)
				chk[s[ii] - 'a'] = 1;
			fup(ii, 0, 25, 1)
			{
				if (chk[ii])pos[ii] = 0;
			}
		}
		if (!finish)
		{
			int cnt = 0;
			fup(i, 0, 25, 1)
				if (pos[i])cnt++;
			if (cnt == 1)finish = 1;
		}
	}
	printf("%d", ans);
}