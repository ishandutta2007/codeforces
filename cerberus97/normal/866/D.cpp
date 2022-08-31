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

const int N = 3e5 + 10;

int main() {
	int n;
	scanf("%d", &n);
	ll ans = 0;
	priority_queue <int, vector <int>, greater <int>> q;
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		if (!q.empty() and q.top() < a) {
			ans += a - q.top();
			q.pop();
			q.push(a);
		}
		q.push(a);
	}
	printf("%lld", ans);
}