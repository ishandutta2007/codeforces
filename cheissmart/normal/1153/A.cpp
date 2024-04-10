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

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int n, t, mn = INF, ans;
	cin >> n >> t;
	for(int i=1;i<=n;i++) {
		int s, d;
		cin >> s >> d;
		while(s < t) s += d;
		if(s < mn) {
			mn = s;
			ans = i;
		}
	}
	cout << ans << endl;
}