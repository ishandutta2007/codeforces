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

const int INF = 1e9 + 7, N = 1e5 + 7;

int bit[N]; // [1, n]

int lowbit(int x) {
	return x & -x;
}

void add(int i, int d) {
	while(i <= 100000) {
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

int r[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;	
		if(r[t] == 0) {
			add(i, 1);
		}
		r[t] = i;
	}
	int ans = 0;
	for(int i=1;i<=100000;i++)
		if(r[i])
			ans += qry(r[i]-1);
	cout << ans << endl;	
}