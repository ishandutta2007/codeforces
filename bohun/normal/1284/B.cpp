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
int l;
int sum[1000005];
int a;

vector <int> qq;

ll ans;

int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &l);
		int maxi = 0;
		int mini = 1e6 + 11;
		bool ok = 1;
		for(int j = 1; j <= l; ++j) {
			scanf("%d", &a);
			if(a > mini) ok = 0;
			maxi = max(maxi, a);
			mini = min(mini, a);
		}
		if(ok) {
			sum[mini]++;
			qq.pb(maxi);
		}
	}

	ans = 1ll * n * n;
	for(int i = 1000000; 0 <= i; --i)
		sum[i] += sum[i + 1];
	for(auto it : qq)
		ans -= sum[it];
	printf("%lld", ans);



	return 0;
}