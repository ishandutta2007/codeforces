#include <bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> vL, vR;
bool can[N];
int dL[N], id[N], L[N], R[N], a[N], s[N], h[N];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", s + i, h + i), id[i] = i;
	sort(id + 1, id + m + 1, [](int i, int j) {
		return s[i] < s[j];
	});
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int p = 1; p <= n; p++) {
		for (int t = 0; t < 2; t++) {
			vL.clear();
			vR.clear();
			bool oL = false, oR = false;
			int cl = 0, cr = 0, ex = 0;
			for (int i = 1; i <= m; i++) {
				int j = id[i];
				if (s[j] < p) L[++cl] = j;
				if (s[j] > p) R[++cr] = j;
				if (s[j] == p) ex = j;
			}
			if (ex == 0 && (t == 0 && cr == 0 || t == 1 && cl == 0)) continue;
			L[cl + 1] = m + 1;
			if (t && ex == 0) s[m + 1] = p + 1;
			else s[m + 1] = p;
			cl++;
			can[cl] = true;
			for (int i = cl - 1; i >= 1; i--) {
				int hp = h[L[i]];
				bool valid = true;
				dL[i] = 0;
				can[i] = false;
				for (int j = i + 1, x = s[L[i]]; j <= cl; j++) {
					for (; x < s[L[j]]; x++) {
						hp += a[x];
						if (hp < 0) {
							valid = false;
							break;
						}
					}
					if (!valid) break;
					can[i] |= can[j];
					dL[i] = max(dL[i], j);
				}
			}
			if (can[1]) {
				oL = true;
				int cur = 1;
				while (true) {
					vL.push_back(cur);
					if (cur == cl) break;
					for (int j = cur + 1; j <= dL[cur]; j++) if (can[j]) {
						cur = j;
						break;
					}
				}
			}
			R[0] = m + 1;
			if (t) s[m + 1] = p;
			else if (ex == 0) s[m + 1] = p - 1;
			can[0] = true;
			for (int i = 1; i <= cr; i++) {
				int hp = h[R[i]];
				bool valid = true;
				dL[i] = cr;
				can[i] = false;
				for (int j = i - 1, x = s[R[i]]; j >= 0; j--) {
					for (; x > s[R[j]]; x--) {					
						hp += a[x];
						if (hp < 0) {
							valid = false;
							break;
						}
					}
					if (!valid) break;
					can[i] |= can[j];
					dL[i] = min(dL[i], j);
				}
			}
			if (can[cr]) {
				oR = true;
				int cur = cr;
				while (true) {
					vR.push_back(cur);
					if (!cur) break;
					for (int j = cur - 1; j >= dL[cur]; j--) if (can[j]) {
						cur = j;
						break;
					}
				}
			}
			if (oL && oR) {
				printf("%d\n", p);
				if (ex) printf("%d ", ex);
				R[0] = 0;
				if (t) {
					for (int i = int(vL.size()) - 2; i >= 0; i--) {
						for (int j = vL[i]; j < vL[i + 1]; j++) printf("%d ", L[j]);
					}
					for (int i = int(vR.size()) - 2; i >= 0; i--) {
						for (int j = vR[i]; j > vR[i + 1]; j--) printf("%d ", R[j]);
					}
				} else {
					for (int i = int(vL.size()) - 2; i >= 0; i--) {
						for (int j = vL[i]; j < vL[i + 1]; j++) printf("%d ", L[j]);
					}
					for (int i = int(vR.size()) - 2; i >= 0; i--) {
						for (int j = vR[i]; j > vR[i + 1]; j--) printf("%d ", R[j]);
					}
				}
				return 0;
			}
		}
	}
	return puts("-1"), 0;
}