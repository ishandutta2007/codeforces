#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>
#include <complex>

#define ld double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) (ll)((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(t) FOR(name_that_will_never_apper, 0, t)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvch vector<vch>
#define vvb vector<vb>
#define vs vector<string>
#define vss vector<vs>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define base complex<double>
#define PI 3.141592653589793
#define alphabet_size 26
using namespace std;

#define mod 1000000007
#define INF (ll)1e18
#define MAXN 100001

vi g[MAXN];
vch used;



int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	vpii a(n + 1);
	FOR(i, 0, n)
		cin >> a[i + 1].X >> a[i + 1].Y;

	FOR(i, 1, n + 1)
		if (a[i].Y != 0)
			g[a[i].Y].push_back(i), g[i].push_back(a[i].Y);


	auto b = a;

	vpii x;
	vch used(n + 1, 0);
	int s, f, t;
	FOR(i,1,n+1)
		if (a[i].X == 0)
		{
			s = i;
			t = i;
			while (t != 0)
			{
				f = t;
				t = a[t].Y;
				
			}
			x.push_back(MP(s, f));
		}

	if (x.size() > 1)
	{
		b[x[0].Y].Y = x[1].X;
		FOR(i, 1, x.size() - 1)
		{
			b[x[i].X].X = x[i - 1].Y;
			b[x[i].Y].Y = x[i + 1].X;
		}
		b[x[x.size() - 1].X].X = x[x.size() - 2].Y;
	}

	FOR(i, 1, n + 1)
		cout << b[i].X << " " << b[i].Y << endl;
	//cin >> n;
	return 0;
}