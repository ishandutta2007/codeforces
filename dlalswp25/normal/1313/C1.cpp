#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll L[505050];
ll R[505050];
ll M[505050];

int A[505050];

vector<pair<ll, int> > v;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &M[i]);

	ll sum = 0;
	for(int i = 1; i <= N; i++) {
		sum += M[i];
		int c = 0;
		while(v.size() && v.back().first >= M[i]) {
			sum -= (v.back().first - M[i]) * v.back().second;
			c += v.back().second;
			v.pop_back();
		}
		v.push_back({M[i], c + 1});
		L[i] = sum;
	}

	v.clear();

	sum = 0;
	for(int i = N; i >= 1; i--) {
		sum += M[i];
		int c = 0;
		while(v.size() && v.back().first >= M[i]) {
			sum -= (v.back().first - M[i]) * v.back().second;
			c += v.back().second;
			v.pop_back();
		}
		v.push_back({M[i], c + 1});
		R[i] = sum;
	}

	// for(int i = 1; i <= N; i++) printf("%lld ", L[i]);

	ll ans = 0, ansi;
	for(int i = 1; i <= N; i++) {
		if(L[i] + R[i] - M[i] > ans) { ans = L[i] + R[i] - M[i]; ansi = i; }
	}

	A[ansi] = M[ansi];
	int h = A[ansi];
	for(int i = ansi - 1; i >= 1; i--) {
		if(M[i] < h) h = M[i];
		A[i] = h;
	}

	h = A[ansi];
	for(int i = ansi + i; i <= N; i++) {
		if(M[i] < h) h = M[i];
		A[i] = h;
	}

	for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");

	return 0;
}