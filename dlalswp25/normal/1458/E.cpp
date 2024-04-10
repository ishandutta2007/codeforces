#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, Q;
pii A[101010];
vector<pii> v;
set<int> S;

void upd(int& y) {
	while(S.size() && *S.begin() == y) {
		S.erase(S.begin());
		y++;
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d%d", &A[i].first, &A[i].second);
	N++; A[N] = {0, 0};
	sort(A + 1, A + N + 1);

	v.emplace_back(0, 0);

	int p = 1;
	while(p <= N && A[p].first == 0) {
		S.insert(A[p].second);
		p++;
	}

	S.erase(0);
	int x = 1, y = 1;
	while(S.size() || p <= N) {
		upd(y);
		if(p <= N && x == A[p].first) {
			if(A[p].second > y) {
				v.emplace_back(x, y);
				S.insert(y);
			}
			else v.emplace_back(A[p]);
			while(p <= N && A[p].first == x) {
				if(A[p].second >= y) S.insert(A[p].second);
				p++;
			}
			x++;
		}
		else {
			v.emplace_back(x, y);
			int nx = (p <= N ? A[p].first : 2020202020);
			if(!S.size() || *S.begin() - y > nx - x) {
				int d = nx - x;
				x += d;
				y += d;
			}
			else {
				int d = *S.begin() - y;
				x += d;
				y += d;
			}
		}
	}
	upd(y);
	v.emplace_back(x, y);

	// for(pii i : v) printf("v %d %d\n", i.first, i.second);

	while(Q--) {
		int x, y; scanf("%d%d", &x, &y);
		int t = lower_bound(A + 1, A + N + 1, pii(x, y)) - A;
		if(A[t] == pii(x, y)) puts("LOSE");
		else {
			auto it = lower_bound(v.begin(), v.end(), pii(x + 1, -1));
			assert(it != v.begin());
			it--;
			if(it -> second - y != it -> first - x) puts("WIN");
			else puts("LOSE");
		}
	}

	return 0;
}