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
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int cnt[10];
int num(int k)
{
	fdn(i, k, 0, 1)
		if (cnt[i]>0)return i;
	return -1;
}
int num2(int k)
{
	fdn(i, k-1, 0, 1)
		if (cnt[i]>0)return i;
	return -1;
}
bool any(int k)
{
	fup(i, 0, k, 1)if (cnt[i]>0)return 1;
	return 0;
}
int ans[20];
int main() {
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	if (n < m)
	{
		sort(a.rbegin(), a.rend());
		cout << a;
	}
	else
	{
		fup(i, 0, n - 1, 1)cnt[a[i] - '0']++;
		int first = -1;
		int now = -1;
		fup(i, 0, m - 1, 1)
		{
			int t = num(b[i] - '0');
			if (t == -1)
			{
				first = i;
				break;
			}
			else
			{
				ans[i] = t;
				now = i;
			}
			cnt[t]--;
			if (t < b[i] - '0')break;
		}
		if (first != -1)
		{
			fdn(i, first - 1, 0, 1)
			{
				int t = ans[i];
				cnt[t]++;
				t = num2(t);
				if (t != -1)
				{
					cnt[t]--;
					ans[i] = t;
					now = i;
					break;
				}
			}
		}
		fup(i, 0, now, 1)printf("%d", ans[i]);
		fdn(i, 9, 0, 1)
			while (cnt[i]>0)
			{
				printf("%d", i);
				cnt[i]--;
			}
	}
}