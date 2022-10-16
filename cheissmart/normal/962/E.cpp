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

const int INF = 1e15 + 7, N = 2e5 + 7;

int x[N];
char c[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	V<vi> b, r, p;
	vi v;
	for(int i=0;i<n;i++) {
		cin >> x[i] >> c[i];
		if(c[i] == 'P') v.PB(i);
	}
	if(v.empty()) {
		vi r, b;
		for(int i=0;i<n;i++) if(c[i] == 'R') r.PB(x[i]);
		for(int i=0;i<n;i++) if(c[i] == 'B') b.PB(x[i]);
		int ans = 0;
		ans += (r.size() ? r.back() - r[0] : 0) + (b.size() ?  b.back() - b[0] : 0);
		cout << ans << endl;
		return 0;
	}
	int rf = -1, bf = -1, rl = -1, bl = -1;
	for(int i=0;i<v[0];i++) {
		if(rf == -1 && c[i] == 'R') rf = i;
		if(bf == -1 && c[i] == 'B') bf = i;
	}
	for(int i=n-1;i>v.back();i--) {
		if(rl == -1 && c[i] == 'R') rl = i;
		if(bl == -1 && c[i] == 'B') bl = i;
	}
	int ans = 0;
	if(rf != -1) ans += x[v[0]] - x[rf];
	if(bf != -1) ans += x[v[0]] - x[bf];
	if(rl != -1) ans += x[rl] - x[v.back()];
	if(bl != -1) ans += x[bl] - x[v.back()];
	for(int i=0;i<(int)v.size()-1;i++) {
		vi r, b;
		for(int j=v[i]+1;j<v[i+1];j++) {
			if(c[j] == 'R') r.PB(j);
			if(c[j] == 'B') b.PB(j);
		}
		// len1
		int len1 = INF, len2 = INF;
		if(r.size() && b.size())
			len1 = (x[v[i+1]] - x[v[i]]) * 2;
		// len2
		len2 = x[v[i+1]] - x[v[i]];
		if(r.size()) {
			int mxr = x[r[0]] - x[v[i]];
			r.PB(v[i+1]);
			for(int j=1;j<r.size();j++)
				mxr = max(mxr, x[r[j]] - x[r[j-1]]);
			len2 += x[v[i+1]] - x[v[i]] - mxr;
		}
		if(b.size()) {
			int mxb = x[b[0]] - x[v[i]];
			b.PB(v[i+1]);
			for(int j=1;j<b.size();j++)
				mxb = max(mxb, x[b[j]] - x[b[j-1]]);
			len2 += x[v[i+1]] - x[v[i]] - mxb;
		}
		ans += min(len1, len2);
	}
	cout << ans << endl;

	
}