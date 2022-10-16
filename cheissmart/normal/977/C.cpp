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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if(k == 0) {
		if(a[0] == 1) {
			cout << -1 << endl;
		} else {
			cout << 1 << endl;
		}
		return 0;
	}
	for(int i = 0; i < n;) {
		int j = i;
		while(i < n && a[i] == a[j]) i++;
		if(i == k) {
			cout << a[j] << endl;
			return 0;
		}
	}	
	cout << -1 << endl;
	
}