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

int a;

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k1, k2;
		scanf("%d %d %d", &n, &k1, &k2);
		bool ok = 0;
		for(int i = 1; i <= k1; ++i) {
			scanf("%d", &a);
			if(a == n)
				ok = 1;
		}
		for(int i = 1; i <= k2; ++i)
			scanf("%d", &a);
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");


	}


	return 0;
}