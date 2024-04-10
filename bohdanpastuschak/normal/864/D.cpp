#define CRT_SECURE_NO_WARNINGS
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

#define ld long double
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
using namespace std;
#define mod 1000000007
#define INF (ll)1e18
#define MAXN 200001

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	vi a(n);
	FOR(i, 0, n)
		cin >> a[i];

	vi ye(n + 1,  0);
	FOR(i, 0, n)
		ye[a[i]]++;

	int q = 0;
	FOR(i, 1, n + 1)
		if (ye[i] == 0)
			q++;	

	cout << q << endl;

	set<int> unused;
	FOR(i, 1, n + 1)
		if (ye[i] == 0)
			unused.insert(i);

	int now_min;
	vch inserted(n + 1, 0);
	FOR(i, 0, n)
	{
		if (unused.size() == 0)
			break;

		now_min = *unused.begin();
		if (ye[a[i]] > 1)
		{
			if (a[i] > now_min || inserted[a[i]] == 1)
			{
				ye[a[i]]--;
				a[i] = now_min;
				inserted[a[i]] = 1;
				unused.erase(now_min);
			}
		}

		inserted[a[i]] = 1;
	}

	FOR(i, 0, n)
		cout << a[i] << " ";

	//cin >> n;
	return 0;
}