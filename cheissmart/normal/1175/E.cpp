#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 5e5 + 5;

int a[N], st[20][N];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	vector<pi> v;
	for(int i=0;i<n;i++) {
		int l, r;
		cin >> l >> r;
		v.EB(l, -r);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++) v[i].S = -v[i].S;
	int sz = 1;
	for(int i=1;i<n;i++) 
		if(v[i].S > v[sz-1].S)
			v[sz++] = v[i];
	v.resize(sz);
	n = sz;
	for(int i=0;i<n;i++)
		st[0][i] = upper_bound(v.begin(), v.end(),MP(v[i].S,INF))-v.begin()-1;
	for(int i=1;i<18;i++)
		for(int j=0;j<n;j++)
			st[i][j] = st[i-1][st[i-1][j]];
	for(int i=0;i<m;i++) {
		int x, y;
		cin >> x >> y;
		if(x<v[0].F || y>v.back().S){
			cout << -1 << endl; 
            continue;
        }
		int xs = upper_bound(v.begin(), v.end(),MP(x,INF))-v.begin()-1;
		if(v[xs].S >= y) {
			cout << 1 << endl;
			continue;
		}
		int c = xs, ans = 0;
		for(int i=17;i>=0;i--) {
			if(v[st[i][c]].S < y) {
				c = st[i][c];
				ans += 1<<i;
			}
		}
		if(v[st[0][c]].S < y) cout << -1 << endl;
		else cout << ans + 2 << endl; 
	}
}