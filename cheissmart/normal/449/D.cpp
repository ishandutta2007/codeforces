#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1 << 20, M = 1e9 + 7;

int a[N], pw[N];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

void sub(int& a, int b) {
	a -= b;
	if(a < 0) a += M;
}

signed main()
{
	IO_OP;

	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * 2 % M;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < N; j++) if(j >> i & 1)
			a[j ^ (1 << i)] += a[j];
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(__builtin_popcount(i) & 1) sub(ans, pw[a[i]] - 1);
		else add(ans, pw[a[i]] - 1);
	}
	cout << ans << '\n';

}