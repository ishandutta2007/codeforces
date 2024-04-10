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
#define MAXN 200001

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("door.in", "r", stdin);
	//freopen("door.out", "w", stdout);
	
	int n = 8;
	vs a(n);
	FOR(i, 0, n)
		cin >> a[i];

	int w = 0;
	FOR(i,0,n)
		FOR(j,0,n)
		if (a[i][j] != '.' && a[i][j] != 'k' && a[i][j] != 'K')
		{
			switch (a[i][j])
			{
			case 'Q': w += 9; break;
			case 'B': w += 3; break;
			case 'N': w += 3; break;
			case 'R': w += 5; break;
			case 'P': w += 1; break;

			case 'q': w -= 9; break;
			case 'b': w -= 3; break;
			case 'n': w -= 3; break;
			case 'r': w -= 5; break;
			case 'p': w -= 1; break;
			}
		}

	if (w == 0)
		cout << "Draw";
	else
		if (w > 0)
			cout << "White";
		else
			cout << "Black";

	return 0;
}