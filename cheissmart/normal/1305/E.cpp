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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	if(n < 3) {
		if(m) cout << -1 << endl;
		else {
			for(int i=0;i<n;i++) cout << i + 1 << " ";
			cout << endl;
		}
		return 0;
	}	
	int ub = 0;	
	for(int i=1;i<=n;i++) {
		ub += (i-1)/2;
	}
	if(m > ub) {
		cout << -1 << endl;
		return 0;
	}
	vi v;
	ub = 0;
	for(int i=1;i<=n;i++) {
		ub += (i - 1) / 2;
		if(ub >= m) {
			int cur = i, want = m-(ub-(i-1)/2);
			while(true) {
				int cnt = (cur-1) / 2;
				cnt -= cur - i;
				if(cnt == want) break;
				cur++;
			}
			v.PB(cur);
			break;
		}
		v.PB(i);
	}
	int cur = 100000;
	while(v.size() < n) {
		v.PB(cur);
		cur += 6000;
	}
	for(int i=0;i<n;i++) cout << v[i] << " ";
}