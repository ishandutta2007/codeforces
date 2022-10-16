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

const int INF = 0x3f3f3f3f, N = 200005;

int st[N][20], nxt[N], lst[N], stt[N][20], a[N], b[N];

signed main()
{
	IO_OP;
	
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) nxt[a[i]] = a[(i+1)%n];
	for(int i=0;i<m;i++) cin >> b[i];
	memset(lst, 0x3f, sizeof lst);
	memset(st, 0x3f, sizeof st);
	memset(stt, 0x3f, sizeof stt);
	for(int i=m-1;i>=0;i--) {
		lst[b[i]] = i;
		st[i][0] = lst[nxt[b[i]]];
	}
	for(int j=1;j<20;j++)
		for(int i=0;i<m;i++)
			if(st[i][j-1] != INF)
				st[i][j] = st[st[i][j-1]][j-1];
	for(int i=0;i<m;i++) {
		int p = n-1, k = i;
		for(int j=19;j>=0;j--) {
			if(p >= (1 << j)) {
				p -= (1 << j);
				k = st[k][j];
			}
			if(k == INF) break;
		}
		stt[i][0] = k;
	}
	for(int j=1;j<20;j++)
		for(int i=0;i + (1 << (j-1))<m;i++)
			stt[i][j] = min(stt[i][j-1], stt[i + (1 << (j-1))][j-1]);
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int k = __lg(r - l + 1);
		int rr = min(stt[l][k], stt[r-(1<<k)+1][k]);
		if(rr <= r) cout << 1;
		else cout << 0;
	}
	
}