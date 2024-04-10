#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int ct[1<<20][2];

int main()
{
	IO_OP;
	
	int n, s = 0;
	ll ans = 0;
	cin >> n;
	ct[0][0]++;
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;
		s ^= t;
		ans += ct[s][i&1];
		ct[s][i&1]++;
	}
	cout << ans << endl;
	
}