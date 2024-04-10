#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll S;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		multiset<ll> X, Y;
		scanf("%d", &N); S = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			S += A[i];
			X.insert(A[i]);
		}
		if(N == 1) { puts("YES"); continue; }
		Y.insert(S);
		while(Y.size()) {
			if(X.size() < Y.size()) break;
			auto it = prev(Y.end());
			ll t = *it;
			Y.erase(it);
			ll a = t / 2, b = (t + 1) / 2;
			if(X.find(a) != X.end()) X.erase(X.find(a));
			else Y.insert(a);
			if(X.find(b) != X.end()) X.erase(X.find(b));
			else Y.insert(b);
		}
		if(Y.size()) puts("NO");
		else puts("YES");
	}
	return 0;
}