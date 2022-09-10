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

#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rep0(i, n) for(ll i = (0); i < (n); i++)
#define repd(i,m,n) for(ll i=(m); i > (n); i--)
#define iter(el, arr) for(auto& el : arr)
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

#define ld double
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll,ll>
#define plli pair<pll,ll>
#define MP make_pair
#define SZ(a) ll((a).size())
#define X first
#define Y second

#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
using namespace std;

const ll INF = 1e18;
const ll MAXN = 101;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n, m;
	ll x, y;

	cin >> n >> m >> x >> y;
	vpll a(n), b(m);
	FOR(i, 0, n)
		cin >> a[i].X, a[i].Y = i;
	FOR(i, 0, m)
		cin >> b[i].X, b[i].Y = i;

	sort(ALL(a));
	sort(ALL(b));

	vpii ans;
	int curr_a = 0, curr_b = 0;
	while (curr_a < n && curr_b < m)
	{
		if (a[curr_a].X - x <= b[curr_b].X && b[curr_b].X <= a[curr_a].X + y)
			ans.push_back(MP(a[curr_a].Y + 1, b[curr_b].Y + 1)), curr_a++, curr_b++;
		else
		{
			if (a[curr_a].X - x > b[curr_b].X)
				curr_b++;
			else
				curr_a++;
		}
	}

	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
		cout << ans[i].X << " " << ans[i].Y<< endl;
	
	return 0;
}