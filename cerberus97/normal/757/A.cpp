/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

string s;
int ctr[200] = {0};

int main()
{
	cin >> s;
	for (auto &i : s)
		ctr[i]++;

	int ans = N;

	ans = min(ans, ctr['B']);
	ans = min(ans, ctr['l']);
	ans = min(ans, ctr['b']);
	ans = min(ans, ctr['s']);
	ans = min(ans, ctr['r']);
	ans = min(ans, ctr['u']/2);
	ans = min(ans, ctr['a']/2);

	cout << ans;
}