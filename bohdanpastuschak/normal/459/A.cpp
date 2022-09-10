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
#define PI 3.141592653589793
using namespace std;

#define alphabet_size 26
#define mod 1000000007
#define INF (ll)1e18
#define MAXN 1000001

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("door.in", "r", stdin);
	//freopen("door.out", "w", stdout);
	
	pii a, b;
	cin >> a.X >> a.Y >> b.X >> b.Y;

	if (a.X == b.X)
	{
		cout << a.X + abs(a.Y - b.Y) << " " << a.Y << " ";
		cout << a.X + abs(a.Y - b.Y) << " " << b.Y;
		return 0;
	}

	if (a.Y == b.Y)
	{
		cout << a.X << " " << a.Y + abs(a.X - b.X) << " ";
		cout << b.X << " " << b.Y + +abs(a.X - b.X);
		return 0;
	}

	if (abs(a.X - b.X) != abs(a.Y - b.Y))
		cout << -1;
	else
		cout << a.X << " " << b.Y << " " << b.X << " " << a.Y;
	
	return 0;
}