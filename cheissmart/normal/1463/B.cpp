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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		ll sum0 = 0, sum1 = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(i & 1) sum1 += a[i];
			else sum0 += a[i];
		}
		if(sum0 < sum1) for(int i = 0; i < n; i += 2) a[i] = 1;
		else for(int i = 1; i < n; i += 2) a[i] = 1;
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}

}