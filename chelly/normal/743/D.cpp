#include<bits/stdc++.h>
using namespace std;
const int N(222222);
vector<int> edges[N];
int fa[N], posi[N], ri[N];
long long mx[N * 4], b[N], a[N], inf(1e18);
void build(int k, int le, int ri) {
	if(le == ri) {
		mx[k] = b[le];
		//printf("%d %d %d\n", k, le, a[le]);
	}else {
		int mid(le + ri >> 1);
		build(k + k, le, mid);
		build(k + k + 1, mid + 1, ri);
		mx[k] = max(mx[k + k], mx[k + k + 1]);
	}
}
long long getValue(int k, int le, int ri, int ql, int qr) {
	if(ql <= le && ri <= qr) {
		return mx[k];
	}else if(le > qr || ri < ql) {
		return -inf;
	}else {
		long long res(-inf);
		int mid(le + ri >> 1);
		if(ql <= mid) {
			res = max(res, getValue(k + k, le, mid, ql, qr));
		}
		
		if(mid + 1 <= qr) {
			res = max(res, getValue(k + k + 1, mid + 1, ri, ql, qr));
		}
		return res;
	}
}
void setValue(int k, int le, int ri, int posi, long long newVal) {
	if(le == ri) {
		mx[k] = newVal;
	}else {
		int mid(le + ri >> 1);
		if(posi <= mid) {
			setValue(k + k, le, mid, posi, newVal);
		}else {
			setValue(k + k + 1, mid + 1, ri, posi, newVal);
		}
		mx[k] = max(mx[k + k], mx[k + k + 1]);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		cin >> a[i];
	}
	for(int i(1); i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);	
	}
	fa[1] = 0;
	int cnt(0);
	ri[1] = posi[1] = ++cnt;
	vector<pair<int, int> > q;
	q.push_back(make_pair(1, 0));
	while(!q.empty()) {
		int v(q.back().first), p(q.back().second++);
		if(p != (int)edges[v].size()) {
			int y(edges[v][p]);
			if(y != fa[v]) {
				fa[y] = v;
				ri[y] = posi[y] = ++cnt;
				q.push_back(make_pair(y, 0));
			}
		}else {
			a[fa[v]] += a[v];
			ri[fa[v]] = max(ri[fa[v]], ri[v]);
			q.pop_back();
		}
	}
	for(int i(1); i <= n; i++) {
		b[posi[i]] = a[i];
	}
	/*for(int i(1); i <= n; i++) {
		printf("%d %I64d\n", fa[i], a[i]);
	}*/
	build(1, 1, n);
	q.clear();
	q.push_back(make_pair(1, 0));
	long long val(getValue(1, 1, n, posi[1], posi[1]));
	vector<pair<int, long long> > banned;
	banned.push_back(make_pair(posi[1], val));
	setValue(1, 1, n, posi[1], -inf);
	long long ans(val + max(getValue(1, 1, n, 1, posi[1] - 1), getValue(1, 1, n, ri[1] + 1, n)));
	//cout << getValue(1, 1, n, 4, 5) << endl;
	while(!q.empty()) {
		int v(q.back().first), p(q.back().second++);
		if(p != (int)edges[v].size()) {
			int y(edges[v][p]);
			if(y != fa[v]) {
				long long val(getValue(1, 1, n, posi[y], posi[y]));
				q.push_back(make_pair(y, 0));
				banned.push_back(make_pair(posi[y], val));
				setValue(1, 1, n, posi[y], -inf);
				//cout << getValue(1, 1, n, 5, 7) << endl;
				ans = max(ans, val + max(getValue(1, 1, n, 1, posi[y] - 1), getValue(1, 1, n, ri[y] + 1, n)));
			}
		}else {
			q.pop_back();
			setValue(1, 1, n, banned.back().first, banned.back().second);
			banned.pop_back();
		}
	}
	if(ans <= -0.5 * inf) {
		cout << "Impossible" << endl;
	}else {
		cout << ans << endl;
	}
}