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
#include <stdio.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair<int, int>
#define pdd pair<ld, ld>
#define pll pair<ll, ll>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define endl '\n'

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(zxc, 0, i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vch vector<char>

#define vvi vector<vi>
#define vvll vector<vll>
#define vvch vector<vch>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

const ld PI = acos(-1.0);
const ll INF = 1e18;
const ll MAXN = 5001;
const ll mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	
	int cur = 1;
	FOR(i, 0, n)
	{
		FOR(j, 0, n / 2)
			cout << cur << " " << n *n + 1 - cur << " ", ++cur;
		cout << endl;
	}
	cin >> n;


	return 0;
}