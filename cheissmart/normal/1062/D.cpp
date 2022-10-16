#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;

	int n;
	cin >> n;
	ll ans = 0;
	for(int i=2;i<=n;i++) {
		for(int j=2;i*j<=n;j++) {
			ans += j;
		}
	}
	ans *= 4;
	cout << ans << endl;
}