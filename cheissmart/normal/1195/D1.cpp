#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;

int32_t main()
{
	IO_OP;
	
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		int p = 1;
		while(t) {
			int d = t % 10;
			t /= 10;
			ans += p * d % M; ans %= M;
			p *= 10; p %= M;
			ans += p * d % M; ans %= M;
			p *= 10; p %= M;
		}
	}
	cout << ans * n % M << endl;
}