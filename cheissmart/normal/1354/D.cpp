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

const int INF = 1e9 + 7, N = 1e6 + 7;

int bit[N];

int lowbit(int x) {
	return x & -x;
}

void add(int i, int d = 1) {
	while(i < N ) {
		bit[i] += d;
		i += lowbit(i);
	}
}

int qry(int i) {
	int res = 0;
	while(i) {
		res += bit[i];
		i -= lowbit(i);
	}
	return res;
}

signed main()
{
	IO_OP;
	
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		add(t);
	}
	int cnt = n;
	while(q--) {
		int t;
		cin >> t;
		if(t > 0) {
			add(t, 1);
			cnt++;
		} else{
			cnt--;
			t = -t;
			int x = 0, cur = 0;
			for(int i = 19; i >= 0; i--) {
				if((x | (1 << i)) <= n && cur + bit[x | (1 << i)] < t) {
					x |= (1 << i);
					cur += bit[x | (1 << i)];
				}
			}
			add(x + 1, -1);
		}
	}
	if(cnt == 0) cout << 0 << endl;
	else {
		for(int i = 1; i <= n; i++) if(bit[i]) return cout << i << endl, 0;
	}

}