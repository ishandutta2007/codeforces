#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

int main() {
	int T, a, b;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &a, &b);
		printf ("%d\n", (abs(b - a) + 9) / 10);
	}
	return 0;
}