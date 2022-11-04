#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M, K;
int t[200005], a[200005], b[200005];
vector<pair<int, int> > ab, as, bs, np;
multiset<pair<int, int> > nps, npa;
int sm = 0;

void inline resize(int s) {
	while (SZ(npa) < s) {
		if (!SZ(nps)) break;
		npa.insert(*nps.begin());
		sm += nps.begin()->first;
		nps.erase(nps.begin());
	}
	while (SZ(npa) > s) {
		nps.insert(*--npa.end());
		sm -= (--npa.end())->first;
		npa.erase(--npa.end());
	}
	while (s && SZ(npa) == s && SZ(nps) && *--npa.end() > *nps.begin()) {
		nps.insert(*--npa.end());
		sm -= (--npa.end())->first;
		npa.erase(--npa.end());
		npa.insert(*nps.begin());
		sm += nps.begin()->first;
		nps.erase(nps.begin());
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	int absm = 0, ass = 0, bss = 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d%d", t + i, a + i, b + i);
		if (a[i] && b[i]) ab.emplace_back(t[i], i);
		else if (a[i]) as.emplace_back(t[i], i), ass += t[i];
		else if (b[i]) bs.emplace_back(t[i], i), bss += t[i];
		else np.emplace_back(t[i], i);
	}
	sort(ab.begin(), ab.end());
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(np.begin(), np.end());
	for (auto &i : np) nps.insert(i);
	for (int i = K; i < SZ(as); ++i) nps.insert(as[i]), ass -= as[i].first;
	for (int i = K; i < SZ(bs); ++i) nps.insert(bs[i]), bss -= bs[i].first;
	for (auto &it : ab) nps.insert(it);
	int ans = INT_MAX;
	int mnp = 0;
	for (int sel = 0; sel <= K; ++sel) {
		int ss = K - sel;
		if (M - sel - ss - ss >= 0) {
			resize(M - sel - ss - ss);
			if (SZ(as) >= ss && SZ(bs) >= ss && SZ(npa) == M - sel - ss - ss) {
				ans = min(ans, absm + ass + bss + sm);
				if (ans == absm + ass + bss + sm) mnp = sel;
			}
		}
		if (sel == SZ(ab)) break;
		if (nps.count(ab[sel])) nps.erase(ab[sel]);
		else npa.erase(ab[sel]), absm -= ab[sel].first;
		absm += ab[sel].first;
		if (ss && SZ(as) >= ss) nps.insert(as[ss - 1]), ass -= as[ss - 1].first;
		if (ss && SZ(bs) >= ss) nps.insert(bs[ss - 1]), bss -= bs[ss - 1].first;
	}
	if (ans == INT_MAX) return puts("-1"), 0;
	printf("%d\n", ans);
	ab.clear(); as.clear(); bs.clear(); np.clear();
	for (int i = 1; i <= N; ++i) {
		if (a[i] && b[i]) ab.emplace_back(t[i], i);
		else if (a[i]) as.emplace_back(t[i], i), ass += t[i];
		else if (b[i]) bs.emplace_back(t[i], i), bss += t[i];
		else np.emplace_back(t[i], i);
	}
	sort(ab.begin(), ab.end());
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(np.begin(), np.end());
	nps.clear(); npa.clear();
	for (auto &i : np) nps.insert(i);
	for (int i = K; i < SZ(as); ++i) nps.insert(as[i]), ass -= as[i].first;
	for (int i = K; i < SZ(bs); ++i) nps.insert(bs[i]), bss -= bs[i].first;
	for (auto &it : ab) nps.insert(it);
	vector<int> se;
	for (int sel = 0; sel <= K; ++sel) {
		int ss = K - sel;
		if (sel == mnp) {
			resize(M - sel - ss - ss);
			for (int i = 0; i < ss; ++i) se.push_back(as[i].second);
			for (int i = 0; i < ss; ++i) se.push_back(bs[i].second);
			for (auto &it : npa) se.push_back(it.second);
			break;
		}
		if (sel == SZ(ab)) break;
		if (nps.count(ab[sel])) nps.erase(ab[sel]);
		else npa.erase(ab[sel]), absm -= ab[sel].first;
		absm += ab[sel].first;
		se.push_back(ab[sel].second);
		if (ss && SZ(as) >= ss) nps.insert(as[ss - 1]), ass -= as[ss - 1].first;
		if (ss && SZ(bs) >= ss) nps.insert(bs[ss - 1]), bss -= bs[ss - 1].first;
	}
	for (int i : se) printf("%d ", i);
	return 0;
}