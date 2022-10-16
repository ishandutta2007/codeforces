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

const int INF = 1e9 + 7, N = 100005;

int pos[N], fd[N];

int bit[N]; // [1, n]

int lowbit(int x) {
	return x & -x;
}

void add(int i, int d = 1) {
	while(i < N) {
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
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			bit[i] = 0;
		for(int i=1;i<=n;i++) {
			int t;
			cin >> t;
			pos[t] = i;
		}
		for(int i=0;i<m;i++) {
			int t;
			cin >> t;
			fd[i] = pos[t];
		}
		int ans = 0;
		for(int i=0;i<m;) {
			int x = fd[i];
			ans += (x - 1 - qry(x-1)) * 2 + 1;
			add(x);
			i++;
			while(i < m && fd[i] < x) {
				add(fd[i]);
				ans++;
				i++;
			}
		}
		cout << ans << endl;


	}	
	
}