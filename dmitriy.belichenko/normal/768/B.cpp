#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 200001;
int a[MAXN];
const int INF = 2000 * 1000 * 1000 + 2;
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ll n;
	ll l;
	ll r;
	int bt = 1;
	cin >> n >> l >> r;
	while ((1ll << bt) <= n) bt++;
	int ans = 0;
	for (ll i = l; i <= r; i++)
	{
		ll x = i;
		for (int j = bt - 1; j >= 0; j--)
		{
			ll d = (1ll << j) - 1;
			if (x <= d) continue;
			else if (x == d + 1)
			{
				ans += ((n >> (bt - 1 - j)) & 1);
				break;
			}
			else x -= (d + 1);
		}
	}
	cout << ans << endl;
	return 0;
}