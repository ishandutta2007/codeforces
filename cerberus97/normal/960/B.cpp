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

const int N = 1e3 + 10;

ll a[N], b[N];
priority_queue<ll> q;

int main() {
	int n, k1, k2;
	scanf("%d%d%d", &n, &k1, &k2);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &b[i]);
		q.push(max(a[i] - b[i], b[i] - a[i]));
	}
	int k = k1 + k2;
	while (k) {
		int cur = q.top();
		q.pop();
		--cur;
		if (cur == -1) {
			cur = 1;
		}
		q.push(cur);
		--k;
	}
	ll ans = 0;
	while(!q.empty()) {
		ll i = q.top();
		q.pop();
		ans += i * i;
	}
	printf("%lld", ans);
}