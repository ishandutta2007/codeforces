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
	int n, ctr[3] = {0};
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		ctr[x]++;
	}

	int ans = min(ctr[1], ctr[2]);
	ctr[1] -= ans;
	ans += ctr[1] / 3;
	cout << ans;
}