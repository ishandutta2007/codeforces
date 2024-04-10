#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

int solve() {
	int n;
	scanf("%d", &n);
	int s = 0, res = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		s += x;
		res = max(res, s);
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", solve() + solve());
	}
	return 0;
}