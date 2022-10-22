#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int a[200005];

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int L = -1;
		int R = -1;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			if(i > 1 && abs(a[i] - a[i - 1]) >= 2) {
				L = i - 1;
				R = i;
			}
		}
		if(L != -1) {
			printf("YES\n");
			printf("%d %d\n", L, R);
		}
		else {
			printf("NO\n");
		}
	}


	return 0;
}