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

int a[102];

signed main()
{
	IO_OP;
	
	int n, sm = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		sm += a[i];
	}	
	sort(a, a+n);
	int req = (9 * n + 1) / 2;
	if(sm >= req) {
		cout << 0 << endl;
		return 0;
	}
	for(int i=0;i<n;i++) {
		sm -= a[i];
		sm += 5;
		if(sm >= req) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	
}