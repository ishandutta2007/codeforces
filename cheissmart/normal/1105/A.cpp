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

int a[1003];

signed main()
{
	IO_OP;
	int n, mn = INF, t;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=1;i<100;i++) {
		int cost = 0;
		for(int j=0;j<n;j++) {
			if(abs(a[j] - i) <= 1) continue;
			else if(a[j] > i) cost += a[j] - i - 1;
			else cost += i - a[j] - 1;
		}
		if(cost < mn) {
			mn = cost;
			t = i;
		}
	}
	cout << t << " " << mn << endl;
	
}