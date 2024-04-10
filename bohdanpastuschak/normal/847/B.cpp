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

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	vi a(n);
	FOR(i, 0, n)
		cin >> a[i];

	vi curr = { 0 };
	int m = curr.size();
	vvi ans;
	ans.push_back(vi(1, a[0]));
	int le, re, me;
	FOR(i, 1, n)
	{
		if (a[curr[m - 1]] >= a[i])
			curr.push_back(i), ans.push_back(vi(1, a[i])), m++;
		else
		{
			le = 0, re = m - 1;
			while (re - le > 1)
			{
				me = (le + re) / 2;
				if (a[curr[me]] < a[i])
					re = me;
				else
					le = me;
			}

			if (a[curr[le]] >= a[i])
				le++;

			curr[le] = i;
			ans[le].push_back(a[i]);
		}
	}

	FOR(i, 0, ans.size())
	{
		FOR(j, 0, ans[i].size())
			cout << ans[i][j] << " ";
		cout << endl;
	}
	//cin >> n;
	return 0;
}