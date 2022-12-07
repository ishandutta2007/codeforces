#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
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
#define INF 98765
#define PI 3.141592653589793238462643383279502884
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

map<string, int> M;
string s, t;
struct AA {
	char type;
	string val;
	int a, b;
}A[5000];
int temp[5000][2];
string mn, mx;
int main() {
	SYNC;
	int n, m;
	cin >> n >> m;
	fup(i, 0, n - 1, 1)
	{
		cin >> s >> t;
		M[s] = i;
		cin >> s;
		if (s[0] == '0' || s[0] == '1')
		{
			A[i].type = 'N';
			A[i].val = s;
		}
		else
		{
			if (s[0] == '?')A[i].a = -1;
			else A[i].a = M[s];
			cin >> s >> t;
			A[i].type = s[0];
			if (t[0] == '?')A[i].b = -1;
			else A[i].b = M[t];
		}
	}
	fup(k, 0, m - 1, 1)
	{
		int t0 = 0, t1 = 0;
		fup(i, 0, n - 1, 1)
		{
			if (A[i].type == 'N')
			{
				temp[i][0] = temp[i][1] = A[i].val[k] - '0';
			}
			else
			{
				int aa, bb;
				if (A[i].a == -1)aa = 0;
				else aa = temp[A[i].a][0];
				if (A[i].b == -1)bb = 0;
				else bb = temp[A[i].b][0];
				if (A[i].type == 'O')temp[i][0] = aa | bb;
				else if (A[i].type == 'X')temp[i][0] = aa ^ bb;
				else if (A[i].type == 'A')temp[i][0] = aa & bb;

				if (A[i].a == -1)aa = 1;
				else aa = temp[A[i].a][1];
				if (A[i].b == -1)bb = 1;
				else bb = temp[A[i].b][1];
				if (A[i].type == 'O')temp[i][1] = aa | bb;
				else if (A[i].type == 'X')temp[i][1] = aa ^ bb;
				else if (A[i].type == 'A')temp[i][1] = aa & bb;
			}
			t0 += temp[i][0], t1 += temp[i][1];
		}
		if (t0 == t1)mn += '0', mx += '0';
		else if (t0 > t1)mn += '1', mx += '0';
		else mn += '0', mx += '1';
	}
	cout << mn << '\n' << mx;
}