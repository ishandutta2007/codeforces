#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int32_t main() {
	
	int n, g = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		g = __gcd(g,t);
	}
	int ans = 0;
	for(int i=1;i*i<=g;i++) {
		if(g % i == 0) {
			ans++;
			if(g/i != i) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}