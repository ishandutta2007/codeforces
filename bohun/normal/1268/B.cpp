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

int n;
int a;
ll bl, wh;

int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		if(i % 2 == 1) {
			bl += a / 2;
			wh += (a + 1) / 2;
		}
		else {
			bl += (a + 1) / 2;
			wh += a / 2;
		}
	}
	printf("%lld", min(bl, wh));




	return 0;
}