#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[8008], b[8008], yes[8008];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		memset(yes, 0, sizeof yes);
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++)
			b[i] = a[i] + b[i-1];
		for(int i = 0; i < n; i++) {
			for(int j = i + 2; j <= n; j++) {
				if(b[j] - b[i] <= n)
					yes[b[j] - b[i]] = 1;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(yes[a[i]]) cnt++;
		cout << cnt << '\n';
	}
	
}