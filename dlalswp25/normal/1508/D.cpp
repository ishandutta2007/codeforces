#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> pp;

int N;
int p[2020];
int pos[2020];
bool vst[2020];
vector<pii> ans;

vector<pp> v;

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		if(z == i) continue;
		v.emplace_back(pii(x, y), pii(i, z));
	}

	if(!v.size()) { puts("0"); return 0; }

	sort(v.begin(), v.end());
	int x0 = v[0].first.first, y0 = v[0].first.second;
	sort(v.begin() + 1, v.end(), [&](const pp& a, const pp& b) {
		int ax = a.first.first - x0, ay = a.first.second - y0;
		int bx = b.first.first - x0, by = b.first.second - y0;
		return (ll)ax * by > (ll)bx * ay;
	});

	int M = v.size();
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 0; i < M; i++) unite(v[i].second.first, v[i].second.second);

	//for(auto i : v) printf("%d %d %d %d\n", i.first.first, i.first.second, i.second.first, i.second.second);

	for(int i = 1; i < M - 1; i++) {
		int a = v[i].second.first, b = v[i + 1].second.first;
		if(par(a) == par(b)) continue;
		unite(a, b);
		ans.emplace_back(v[i].second.first, v[i + 1].second.first);
		swap(v[i].second.second, v[i + 1].second.second);
	}

	for(int i = 0; i < M; i++) pos[v[i].second.first] = i;

	for(int i = 0; i < M - 1; i++) {
		int t = v[0].second.second;
		int x = pos[t];
		ans.emplace_back(v[0].second.first, v[x].second.first);
		swap(v[0].second.second, v[x].second.second);
	}

	printf("%d\n", ans.size());
	for(auto i : ans) printf("%d %d\n", i.first, i.second);

	return 0;
}