#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vector<pi> v[10005], h[10005];
vi d[10005];
int a[10005], bit[10005];

int qry(int x) {
	int ret = 0;
	while(x) {
		ret += bit[x];
		x -= x & -x;
	}
	return ret;
}

void add(int x, int y) {
	while(x < 10005) {
		bit[x] += y;
		x += x & -x;
	}
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 5001, y1 += 5001, x2 += 5001, y2 += 5001; 
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		if(x1 == x2) {
			v[x1].EB(y1, y2);
		} else {
			h[y1].EB(x1, x2);
		}
	}
	int ans = 0;
	for(int x=1;x<10005;x++) {
		for(pi p:v[x]) {
			memset(bit, 0, sizeof bit);
			for(int i=1;i<10005;i++)
				d[i].clear();
			for(int y=p.F;y<=p.S;y++)
				for(pi pp:h[y])
					if(pp.F <= x && pp.S > x) {
						add(y, 1);
						d[pp.S].PB(y);
					}
			for(int xx=x+1;xx<10005;xx++) {
				for(pi pp:v[xx]) {
					int t = qry(pp.S) - qry(pp.F - 1);
					ans += t*(t-1)/2;
				}
				for(int i:d[xx])
					add(i, -1);
			}
		}
	}
	cout << ans << endl;
}