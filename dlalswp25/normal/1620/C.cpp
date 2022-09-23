#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1000000000000000001LL;

int N, K;
ll X;
char A[2020];

ll mul(ll a, ll b) {
	ll ret = 0;
	while(b) {
		if(b & 1) ret += a;
		a += a;
		b >>= 1;
		if(a > INF) a = INF;
		if(ret > INF) ret = INF;
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		scanf("%lld", &X);
		X--;
		vector<int> v;
		scanf("%s", A + 1);
		int c = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == 'a') {
				v.push_back(c);
				c = 0;
			}
			else c++;
		}
		v.push_back(c);

		vector<ll> m(v.size());
		m.back() = 1;
		for(int i = (int)v.size() - 2; i >= 0; i--) {
			m[i] = mul(m[i + 1], K * v[i + 1] + 1);
		}

		vector<int> ans(v.size());
		for(int i = 0; i < v.size(); i++) {
			ans[i] = X / m[i];
			X %= m[i];
		}
		for(int i = 0; i < v.size(); i++) {
			for(int j = 0; j < ans[i]; j++) printf("b");
			if(i + 1 != v.size()) printf("a");
		}
		puts("");
	}
	return 0;
}