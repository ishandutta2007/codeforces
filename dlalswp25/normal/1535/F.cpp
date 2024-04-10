#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int XXX = 1337;

struct BIT {
	int N;
	int T[202020];

	void init(int n) {
		N = n;
		for(int i = 1; i <= N; i++) T[i] = 0;
	}

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}
	
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int query(int l, int r) {
		return get(r) - get(l - 1);
	}
}bit;

struct Strings {
	string s, r, sorted;
	int cnt;
	int sx, rx;
	vector<int> su, sd, ru, rd;
}A[202020];

struct Query {
	int y1, y2, c;

	Query(int _y1, int _y2, int _c) : y1(_y1), y2(_y2), c(_c) {}
};

int N, M;
string S[202020];
vector<Query> q[202020];
vector<pii> U[202020];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) cin >> S[i];
	M = S[1].size();

	sort(S + 1, S + N + 1);
	int id = 0;
	for(int i = 1; i <= N; i++) {
		if(S[i] == S[i - 1]) {
			A[id].cnt++;
		}
		else {
			id++;
			A[id].s = S[i];
			A[id].r = A[id].sorted = A[id].s;
			reverse(A[id].r.begin(), A[id].r.end());
			sort(A[id].sorted.begin(), A[id].sorted.end());
			A[id].cnt = 1;
		}
	}
	N = id;

	sort(A + 1, A + N + 1, [&](Strings& a, Strings& b) {
		return a.sorted < b.sorted;
	});

	ll ans = 0;

	ll tot = 0;
	int l = 1, r;

	for(int i = 2; i <= N + 1; i++) {
		if(A[i].sorted != A[i - 1].sorted) {
			r = i - 1;

			// printf("%d %d\n", l, r);

			sort(A + l, A + r + 1, [&](Strings a, Strings b) {
				return a.s < b.s;
			});

			for(int j = l; j <= r; j++) A[j].sx = j - l + 1;

			for(int j = 0; j < M; j++) {
				for(int k = l; k <= r; k++) {
					int t = 1;
					if(k == l || A[k].s[j] != A[k - 1].s[j]) t = k - l + 1;
					else {
						if(j) t = A[k].su[j - 1];
						t = max(t, A[k - 1].su[j]);
					}
					A[k].su.push_back(t);
				}
				for(int k = r; k >= l; k--) {
					int t = r - l + 1;
					if(k == r || A[k].s[j] != A[k + 1].s[j]) t = k - l + 1;
					else {
						if(j) t = A[k].sd[j - 1];
						t = min(t, A[k + 1].sd[j]);
					}
					A[k].sd.push_back(t);
				}
			}

			sort(A + l, A + r + 1, [&](Strings a, Strings b) {
				return a.r < b.r;
			});

			for(int j = l; j <= r; j++) A[j].rx = j - l + 1;

			for(int j = 0; j < M; j++) {
				for(int k = l; k <= r; k++) {
					int t = 1;
					if(k == l || A[k].r[j] != A[k - 1].r[j]) t = k - l + 1;
					else {
						if(j) t = A[k].ru[j - 1];
						t = max(t, A[k - 1].ru[j]);
					}
					A[k].ru.push_back(t);
				}
				for(int k = r; k >= l; k--) {
					int t = r - l + 1;
					if(k == r || A[k].r[j] != A[k + 1].r[j]) t = k - l + 1;
					else {
						if(j) t = A[k].rd[j - 1];
						t = min(t, A[k + 1].rd[j]);
					}
					A[k].rd.push_back(t);
				}
			}

			for(int j = l; j <= r; j++) {
				reverse(A[j].ru.begin(), A[j].ru.end());
				reverse(A[j].rd.begin(), A[j].rd.end());
			}

			for(int j = 1; j <= r - l + 1; j++) U[j].clear();
			for(int j = l; j <= r; j++) U[A[j].sx].emplace_back(A[j].rx, A[j].cnt);

			ll sum = 0, zero = 0;
			for(int j = l; j <= r; j++) {
				sum += A[j].cnt;
				zero += (ll)A[j].cnt * (A[j].cnt - 1) / 2;
			}

			ll cnt = 0;

			for(int j = 1; j <= r - l + 1; j++) q[j].clear();

			for(int j = l; j <= r; j++) {
				int lft = 0;
				A[j].s.push_back(0);
				// printf("%s\n", A[j].s.c_str());
				for(int k = 1; k <= M; k++) {
					if(A[j].s[k - 1] > A[j].s[k]) {
						int x1, y1, x2, y2;
						if(lft == 0) { x1 = 1; x2 = r - l + 1; }
						else { x1 = A[j].su[lft - 1]; x2 = A[j].sd[lft - 1]; }
						if(k == M) { y1 = 1; y2 = r - l + 1; }
						else { y1 = A[j].ru[k]; y2 = A[j].rd[k]; }
						cnt -= (ll)A[j].cnt * A[j].cnt;

						if(x1 > 1) q[x1 - 1].emplace_back(y1, y2, -A[j].cnt);
						q[x2].emplace_back(y1, y2, A[j].cnt);

						// printf("%d %d : %d %d %d %d\n", lft, k - 1, x1, y1, x2, y2);
						// printf("%lld\n", cnt);
						lft = k;
					}
				}
			}

			bit.init(r - l + 1);

			for(int j = 1; j <= r - l + 1; j++) {
				for(pii k : U[j]) {
					// printf("upd %d %d\n", k.first, k.second);
					bit.upd(k.first, k.second);
				}
				for(auto& k : q[j]) {
					// printf("query %d %d %d\n", k.y1, k.y2, k.c);
					cnt += (ll)k.c * bit.query(k.y1, k.y2);
				}
			}

			// printf("%lld %lld %lld\n", sum, cnt, zero);

			ll s12 = (ll)sum * (sum - 1) / 2 - zero;
			ans += 2 * s12 - cnt;

			ans += tot * sum * XXX;
			tot += sum;
			sum = 0;
			l = i;
		}
	}

	printf("%lld\n", ans);
	return 0;
}