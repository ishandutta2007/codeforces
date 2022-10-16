#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int t;
	ll n, k;
	cin >> t;
	while(t--) {
		ll ans = 0;
		cin >> n >> k;
		while(n) {
			if(n % k == 0) n/= k, ans++;
			else {
				ans += n % k;
				n -= n % k;
			}
		}
		cout << ans << endl;
	}
	
}