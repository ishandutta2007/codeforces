/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int ans = n - a - b + c;
	if (ans >= 1 and a <= n and b <= n and c <= min(a, b)) {
		cout << ans;
	} else {
		cout << -1;
	}
}