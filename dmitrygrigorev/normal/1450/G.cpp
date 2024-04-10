#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int a, b;

const int N = (1<<20);

const int INF = 1e9;

bool dp[N];
bool can[N];
bool from[N];

int n;

pair<int, int> left_index[N];
pair<int, int> right_index[N];
int tcnt[N];

bool good(int mask) {
	int cnt = tcnt[mask];

	int delta = right_index[mask].x - left_index[mask].x + 1;

	return ((ll) cnt * b >= (ll) delta * a);

}

void solve(vector<pair<int, int> > v, vector<char> t, vector<int> cnt) {

	if (t.size() == 1) {
		cout << "1 " << t[0] << endl;
		exit(0);
	}

	n = v.size();

	left_index[0] = mp(INF, -1);
	right_index[0] = mp(-INF, -1);
	tcnt[0] = 0;

	for (int i = 1; i < (1<<n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (((1<<j)&i)) {
				left_index[i] = min(left_index[i^(1<<j)], mp(v[j].x, j));
				right_index[i] = max(right_index[i^(1<<j)], mp(v[j].y, j));
				tcnt[i] = tcnt[i^(1<<j)] + cnt[j];
				break;
			}
		}
	}


	for (int i = 0; i < n; ++i) {
		if (good(1<<i)) {
			dp[1<<i] = true;
			from[1<<i] = true;
		}
		can[1<<i] = true;
	}

	for (int i = 1; i < (1<<n); ++i) {

		bool T = good(i);

		vector<pair<int, int> > lin, rin;
		for (int j = 0; j < n; ++j) {
			if (!((1<<j)&i)) continue;
			lin.pb(mp(v[j].x, j));
			rin.pb(mp(v[j].y, j));
		}

		sort(all(lin));
		sort(all(rin));


		for (int take = 0; take < lin.size(); ++take) {

			int M = 0;

			for (int take2 = take; take2 < lin.size(); ++take2) {
				M ^= (1<<lin[take2].y);
				if ((dp[i^M] && can[M]) || (dp[M] && can[i^M])) {
					can[i] = true;
					dp[i] = T;
					from[i] = T;
				}
				if (from[M] && from[i^M]) from[i] = true;
			}

			if (can[i]) break;
		}

		for (int take = 0; take < rin.size(); ++take) {

			int M = 0;

			for (int take2 = take; take2 < rin.size(); ++take2) {
				M ^= (1<<rin[take2].y);
				if ((dp[i^M] && can[M]) || (dp[M] && can[i^M])) {
					can[i] = true;
					dp[i] = T;
					from[i] = T;
				}
				if (from[M] && from[i^M]) from[i] = true;
			}

			if (can[i]) break;
		}

	}

	vector<char> ans;
	for (int i = 0; i < n; ++i) {
		if (from[((1<<n) - 1) ^ (1<<i)]) ans.pb(t[i]);
	}

	sort(all(ans));
	cout << ans.size() << " ";
	for (auto x : ans) cout << x << " ";


}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n >> a >> b;
	string s;
	cin >> s;
	
	vector<pair<int, int> > borders;


	borders.assign(26, mp(INF, -INF));
	vector<int> cnt(26, 0);

	int u = 0;
	for (auto x : s) {
		borders[x - 'a'].x = min(borders[x - 'a'].x, u);
		borders[x - 'a'].y = max(borders[x - 'a'].y, u++);
		cnt[x - 'a']++;
	}

	vector<pair<int, int> > rb;
	vector<char> symb;
	vector<int> t;

	u = 0;
	for (auto el : borders) {
		if (el.x != INF) {
			rb.pb(el);
			symb.pb((char) ('a' + u));
			t.pb(cnt[u]);
		}
		u++;
	}

	solve(rb, symb, t);



}