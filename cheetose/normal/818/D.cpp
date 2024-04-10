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
typedef vector<iii> Viii;
typedef complex<double> base;
int MOD = 10001;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
int DX[] = { 2,2,1,1,-1,-1,-2,-2 }, DY[] = { 1,-1,2,-2,2,-2,1,-1 };

int a[100000];
int cnt[1000001];
map<int, int> M;
map<int, int>::iterator it;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	fup(i, 0, n - 1, 1)scanf("%d", a + i);
	fup(i, 0, n - 1, 1)
		M[a[i]]++;
	int now = M[k];
	M.erase(k);
	fup(i, 1, 1000000, 1)cnt[i] = now;
	fdn(i, n - 1,0, 1)
	{
		if (a[i] == k)now--;
		else
		{
			it = M.find(a[i]);
			if (it == M.end())continue;
			if (it->Y < cnt[a[i]])
			{
				M.erase(it);
				continue;
			}
			if (it->Y <= now)M.erase(it);
			else
			{
				(it->Y)--;
				cnt[a[i]] = now;
			}
		}
	}
	if (M.empty())puts("-1");
	else printf("%d", M.begin()->X);
}