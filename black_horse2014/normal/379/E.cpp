#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-8;
vector<pair<db, db>> V[333], Cur;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout << setprecision(10); 
	int n, k; cin >> n >> k;
	for (int id = 0; id < n; id++) {
		for (int i = 0; i < k+1; i++) {
			int x; cin >> x;
			V[id].emplace_back(i, x);
		}
	}
	for (int i = 0; i < k+1; i++) {
		Cur.emplace_back(i, 0);
	}
	for (int id = 0; id < n; id++) {
		db ans = 0;
		vector<pair<db, db>> New;
		db cx = 0;
		int id1 = 0, id2 = 0;
		New.emplace_back(0, max(V[id][0].second, Cur[0].second));
		while (cx < k-eps) {
			auto f1 = V[id][id1], t1 = V[id][id1+1];
			auto f2 = Cur[id2], t2 = Cur[id2+1];
			db nx1 = t1.first;
			db nx2 = t2.first;
			db a1 = (t1.second-f1.second)/(t1.first-f1.first);
			db b1 = t1.second-t1.first*a1;
			db a2 = (t2.second-f2.second)/(t2.first-f2.first);
			db b2 = t2.second-t2.first*a2;
			db ncx = min(nx1, nx2);
			db v1 = cx * a1 + b1, v2 = cx * a2 + b2;
			db nv1 = ncx * a1 + b1, nv2 = ncx * a2 + b2;
			if (v2 < v1 + eps && nv2 < nv1 + eps) {
				ans += (ncx - cx) * (v1 - v2 + nv1 - nv2) / 2;
			} else if (v2 + eps < v1 && nv1 + eps < nv2) {
				db crx = (b2 - b1) / (a1 - a2);
				db cry = crx * a1 + b1;
				New.emplace_back(crx, cry);
				ans += (v1 - v2) * (crx - cx) / 2;
			} else if (v1 + eps < v2 && nv2 + eps < nv1) {
				db crx = (b2 - b1) / (a1 - a2);
				db cry = crx * a1 + b1;
				New.emplace_back(crx, cry);
				ans += (nv1 - nv2) * (ncx - crx) / 2;
			}
			cx = ncx;
			New.emplace_back(cx, max(nv1, nv2));
			if (nx1 < ncx + eps) id1++;
			if (nx2 < ncx + eps) id2++;
		}
		Cur = New;
		cout << ans << endl;
	}
}