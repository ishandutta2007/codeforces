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

#define ld long double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) ll((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
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
#define PI 3.141592653589793
using namespace std;

#define alphabet_size 26
#define mod 1000000007
#define INF (ll)1e18
#define MAXN 100001

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n; cin >> n;
	
	FOR(i, 0, n)
	{
		REPEAT(n - i)
			cout << "  ";

		if (i != 0)
		{
			FOR(j, 0, i + 1)
				cout << j << " ";
		}
		else
			cout << 0;

		RFOR(j, i, 1)
			cout << j << " ";

		if (i != 0)
			cout << 0;

		cout << endl;
	}
	FOR(i, 0, n + 1)
		cout << i << " ";
	RFOR(i, n, 1)
		cout << i << " ";
	cout << 0;
	cout << endl;
	FOR(k, 0, n)
	{
		int i = n - k - 1;
		REPEAT(n - i)
			cout << "  ";

		if (i != 0)
		{
			FOR(j, 0, i + 1)
				cout << j << " ";
		}
		else
			cout << 0;

		RFOR(j, i, 1)
			cout << j << " ";

		if (i != 0)
			cout << 0;

		cout << endl;
	}

	cin >> n;
	return 0;
}