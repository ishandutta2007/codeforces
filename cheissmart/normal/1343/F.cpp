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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		V<unordered_set<int>> v;
		for(int i = 0; i < n - 1; i++) {
			int k;
			cin >> k;
			unordered_set<int> vv;
			for(int j = 0; j < k; j++) {
				int t;
				cin >> t;
				vv.insert(t);
			}
			v.PB(vv);
		}
		vi ans;
		for(int i = 1; i <= n; i++) {
			V<unordered_set<int>> vv = v;
			vi p({i});
			for(int j = 0; j < n - 1; j++) vv[j].erase(i);
			bool yes = true;
			for(int j = 0; j < n - 1; j++) {
				vi ok;
				for(int k = 0; k < n - 1; k++) {
					if(vv[k].size() == 1) {
						ok.PB(k);
					}
				}
				if(ok.size() != 1) {
					yes = false;
					break;
				}
				unordered_set<int> tt = v[ok[0]];
				int nw = *vv[ok[0]].begin();
				tt.erase(nw);
				if(tt.empty()) {
					yes = false;
					break;
				}
				bool nok = 0;
				for(int i = p.size()-1; tt.size() && i >= 0; i--) {
					if(tt.count(p[i]) == 0) {
						nok = 1;
						break;
					}
					tt.erase(p[i]);
				}
				if(nok) {
					yes = false;
					break;
				}
				p.PB(nw);
				for(int k = 0; k < n - 1; k++) vv[k].erase(nw);
			}
			if(yes) {
				ans = p;
				break;
			}
		}
		for(int i:ans) cout << i << " ";
		cout << endl;
	}
		
}