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

const int INF = 1e9 + 7, N = 300005;

int bit[N+N], pos[N], mn[N], mx[N];

int qry(int x) {
	int ret = 0;
	for(;x;x-=x&-x)
		ret += bit[x];
	return ret;
}

void add(int x, int add = 1) {
	for(;x<N+N;x+=x&-x)
		bit[x] += add;
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	int bk = n+1;
	for(int i=1;i<=n;i++) mx[i] = mn[i] = i, pos[i] = n - i + 1, add(i, 1);
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		mn[t] = 1;
		mx[t] = max(mx[t], n - qry(pos[t] - 1));
		add(pos[t], -1);
		add(pos[t] = bk++, 1);
	}
	for(int i=1;i<=n;i++) 
		mx[i] = max(mx[i], n - qry(pos[i] - 1));

	for(int i=1;i<=n;i++)
		cout << mn[i] << " " << mx[i] << endl;

}