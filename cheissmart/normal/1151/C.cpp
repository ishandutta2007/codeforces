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

const int M = 1e9 + 7;

int f(int x) {
	int a[2] = {};
	for(int i=0,j=0;;i++,j^=1) {
		if((1LL << i) <= x) {
			a[j] = (a[j] + (1LL << i)) % M;
			x -= (1LL << i);
		} else {
			a[j] = (a[j] + x) % M;
			break;
		}
	}
	int ans = 0;
	ans += a[0] * a[0] % M;
	ans = (ans + a[1] * (a[1] + 1)) % M;
	return ans;
}

int32_t main()
{
	IO_OP;
	
	int l, r;
	cin >> l >> r;
	cout << (f(r) - f(l-1) + M) % M << endl;
}