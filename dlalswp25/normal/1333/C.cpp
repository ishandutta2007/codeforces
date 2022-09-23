#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[202020];
ll S[202020];
int N;

int bef[202020];
int no[202020];

vector<ll> v;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		S[i] = S[i - 1] + A[i];
		v.push_back(S[i]);
	}
	S[0] = 0;
	v.push_back(0);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 0; i <= N; i++) S[i] = lower_bound(v.begin(), v.end(), S[i]) - v.begin();

	for(int i = 0; i <= N; i++) bef[i] = -1;
	bef[S[0]] = 0;
	ll ans = 0;

	for(int i = 1; i <= N; i++) {
		no[i] = max(bef[S[i]] + 1, no[i - 1]);
		ans += (i - no[i]);
		bef[S[i]] = i;
	}
	printf("%lld\n", ans);

	return 0;
}