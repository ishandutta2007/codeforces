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
typedef tuple<ll, ll, ll> TT;
ll MOD = 1000000007;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

string s[100000];
ll score(const string& ss)
{
	ll ans = 0;
	ll cnt = 0;
	int N = ss.length();
	fup(i, 0, N - 1, 1)
	{
		if (ss[i] == 's')cnt++;
		else ans += cnt;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	fup(i, 0, n - 1, 1)
	{
		cin >> s[i];
	}
	sort(s, s + n, [&](const string& s1, const string& s2) {
		string S1 = s1 + s2, S2 = s2 + s1;
		return score(S1) > score(S2);
	});
	string ss;
	fup(i, 0, n - 1, 1)
		ss += s[i];
	cout << score(ss);
}