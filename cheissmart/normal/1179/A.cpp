#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[100005], b[100005];

int32_t main()
{
	IO_OP;
	
	int n, q;
	cin >> n >> q;
	deque<int> dk;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		dk.PB(t);
	}
	for(int i=1;i<=n;i++) {
		a[i] = dk.front(); dk.pop_front();
		b[i] = dk.front(); dk.pop_front();
		dk.PB(min(a[i], b[i])), dk.push_front(max(a[i], b[i]));
	}
	while(q--) {
		int m;
		cin >> m;
		if(m <= n) {
			cout << a[m] << " " << b[m] << endl;
			continue;
		}
		m -= n + 1;
		m %= n - 1;
		cout << dk.front() << " " << dk[m+1] << endl;
	}
	
}