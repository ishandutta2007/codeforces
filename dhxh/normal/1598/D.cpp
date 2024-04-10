#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long cnta[maxn];
long long cntb[maxn];
vector <int> A[maxn], B[maxn];

int main() {
	int i, j;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		set <pair <int, int> > s;
		for(i=0;i<=n;i++){
			cnta[i] = cntb[i] = 0;
			A[i].clear();
			B[i].clear();
		}

		for(i=1;i<=n;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			cnta[a]++;
			cntb[b]++;
			A[a].push_back(b);
			B[b].push_back(a);
		}

		long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
		for(i=1;i<=n;i++){
			long long s = 0;
			for(auto x : B[i]){
				s += (cnta[x] - 1) * (cntb[i] - 1);
			}
			ans -= s;
		}
		printf("%lld\n", ans);
	}

	return 0;
}