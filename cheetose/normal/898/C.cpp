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

map<string, vector<string> > M;
map<string, vector<string> >::iterator it;
bool preAB(string a, string b)
{
	if (a.length() > b.length())return 0;
	reverse(ALL(a));
	reverse(ALL(b));
	int n = a.length();
	fup(i, 0, n - 1, 1)
	{
		if (a[i] != b[i])return 0;
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	fup(i, 0, n - 1, 1)
	{
		string name;
		cin >> name;
		int nn;
		cin >> nn;
		while (nn--)
		{
			string s;
			cin >> s;
			M[name].push_back(s);
		}
	}
	map<string, vector<string> > ans;
	for (it = M.begin(); it != M.end(); it++)
	{
		string s = it->first;
		sort(ALL(M[s]));
		M[s].erase(unique(ALL(M[s])), M[s].end());
		int nn = M[s].size();
		vector<bool> chk(nn, false);
		fup(i,0,nn-1,1)
			fup(j, 0, nn - 1, 1)
		{
			if (i == j)continue;
			if (preAB(M[s][i], M[s][j]))
			{
				chk[i] = 1;
				break;
			}
		}
		fup(i, 0, nn - 1, 1)
		{
			if (!chk[i]) ans[s].push_back(M[s][i]);
		}
	}
	cout << ans.size() << '\n';
	for (it = ans.begin(); it != ans.end(); it++)
	{
		string s = it->first;
		cout << s<<' '<<ans[s].size()<<' ';
		fup(i, 0, (int)ans[s].size()-1, 1)
			cout << ans[s][i] << ' ';
		cout << '\n';
	}
}