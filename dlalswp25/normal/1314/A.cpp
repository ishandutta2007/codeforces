#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii A[202020];
int N;

multiset<int> S;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i].first);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i].second);

	sort(A + 1, A + N + 1);
	
	ll ans = 0;
	ll sum = 0;

	int s = 1;

	while(s <= N) {
		sum = 0;
		int p = s;
		int m = A[s].first;
		while(1) {
			if(A[p].first == m) {
				while(p <= N) {
					S.insert(A[p].second);
					sum += A[p].second;
					p++;
					if(A[p].first != m) break;
				}
			}
			auto it = S.end(); it--;
			sum -= (*it); S.erase(it);
			ans += sum;
			m++;
			// printf("%d %lld\n", p, ans);
			if(S.size() < 1) break;
			// printf("%d %d\n", p, m);
		}
		s = p;
	}
	printf("%lld\n", ans);
	
	return 0;
}