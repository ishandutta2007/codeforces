#include <bits/stdc++.h>
// skipped during system testing, want to see if it would have been fine

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct pt {
	int x, y, ind, cval;
	double tanx;
	pt() : x(0), y(0) {}
	pt(int a, int b, int c) : x(a), y(b), ind(c), tanx(tan((double) b/a)) {}
	pt(int a, int b) : x(a), y(b) {}
	pt operator+ (const pt& o) const { return pt(x+o.x, y+o.y); }
	pt operator- (const pt& o) const { return pt(x-o.x, y-o.y); }
	ll nrm () const {
		return (ll) x*x + (ll) y*y;
	}

	bool operator< (const pt& o) const {
		return tanx < o.tanx;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<pt> pts;
	for(int i=0;i<N;++i) {
		int x, y;
		cin >> x;
		cin >> y;
		pts.emplace_back(x, y, i);
	}
	sort(pts.begin(), pts.end());
	pt here(0,0);
	vector<int> ans(N, 0);
	for(int i=0;i<N;++i) {
		if((here+pts[i]).nrm() < (here-pts[i]).nrm()) {
			here = here +pts[i];
			pts[i].cval = 1;
		} else {
			here = here -pts[i];
			pts[i].cval = -1;
		}
		ans[pts[i].ind] = pts[i].cval;
	}
	for(auto& ii : ans) cout << ii << " ";
	cout << endl;
	
	return 0;
}