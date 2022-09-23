#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 1000000;

int N, M;

vector<int> er[1010101];
vector<int> ins[1010101];

struct FWT {
	int T[1010101];
	
	void upd(int x, int v) {
		for(int i = x; i <= MX; i += i&-i) T[i] += v;
	}
	int get(int x) {
		if(x <= 0) return 0;
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

struct Segment {
	int y;
	int x1, x2;

	bool operator< (const Segment& o) const {
		return y > o.y;
	}
}A[101010];

set<int> S;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &A[i].y, &A[i].x1, &A[i].x2);
	}
	N++;
	A[N].y = 0;
	A[N].x1 = 0;
	A[N].x2 = MX;

	sort(A + 1, A + N + 1);

	for(int i = 1; i <= M; i++) {
		int x, y1, y2; scanf("%d%d%d", &x, &y1, &y2);
		if(y2 == MX) {
			fwt.upd(x, 1);
			er[y1].push_back(x);
		}
		else if(y1 == 0) {
			ins[y2].push_back(x);
		}
	}

	ll ans = 0;

	int p = 1;
	for(int i = MX - 1; i >= 0; i--) {
		for(int j : ins[i]) {
			S.insert(j);
		}
		if(A[p].y == i) {
			int x1 = A[p].x1, x2 = A[p].x2;
			ans += fwt.get(x2) - fwt.get(x1 - 1);

			if(x2 - x1 == MX) ans++;

			while(S.size()) {
				int t = *S.begin();
				if(x1 <= t && t <= x2) {
					fwt.upd(t, 1);
					S.erase(S.begin());
				}
				else break;
			}

			while(S.size()) {
				auto it = --S.end();
				int t = *it;
				if(x1 <= t && t <= x2) {
					fwt.upd(t, 1);
					S.erase(it);
				}
				else break;
			}
			// printf("%d %lld\n", p, ans);
			p++;
		}
		for(int j : er[i]) {
			fwt.upd(j, -1);
		}
	}
	printf("%lld\n", ans);

	return 0;
}