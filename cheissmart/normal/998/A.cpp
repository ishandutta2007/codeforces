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

pi a[15];

signed main()
{
	IO_OP;

	int n, sum = 0;
	cin >> n;
	if(n == 1) {
		cout << -1 << endl;
		return 0;
	}
	for(int i=0;i<n;i++) {
		cin >> a[i].F;
		a[i].S = i;
		sum += a[i].F;
	}
	sort(a, a+n);
	if(sum-a[0].F == a[0].F) {
		cout << -1 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << a[0].S + 1 << endl;
	
}