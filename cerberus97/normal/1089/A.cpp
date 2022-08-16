#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

const int P = 210, N = 7;

bool dp[N][P][P][N];
pii back[N][P][P][N];

int main() {
	vector<pii> scores, scores_alt;
	for (int i = 0; i <= 23; ++i) {
		scores.push_back({25, i});
	}
	for (int i = 26; i < P; ++i) {
		scores.push_back({i, i - 2});
	}
	for (int i = 0; i <= 13; ++i) {
		scores_alt.push_back({15, i});
	}
	for (int i = 16; i < P; ++i) {
		scores_alt.push_back({i, i - 2});
	}
	dp[0][0][0][0] = true;
	for (int i = 0; i < 5; ++i) {
		if (i == 4) {
			scores = scores_alt;
		}
		for (int p1 = 0; p1 < P; ++p1) {
			for (int p2 = 0; p2 < P; ++p2) {
				for (int w1 = 0; w1 <= i; ++w1) {
					if (!dp[i][p1][p2][w1]) {
						continue;
					}
					if (w1 == 3 or i - w1 == 3) {
						continue;
					}
					for (auto &s : scores) {
						if (s.first + p1 < P and s.second + p2 < P) {
							dp[i + 1][p1 + s.first][p2 + s.second][w1 + 1] = true;
							back[i + 1][p1 + s.first][p2 + s.second][w1 + 1] = s;
						}
						if (s.first + p2 < P and s.second + p1 < P) {
							dp[i + 1][p1 + s.second][p2 + s.first][w1] = true;
							back[i + 1][p1 + s.second][p2 + s.first][w1] = {s.second, s.first};
						}
					}
				}
			}
		}
	}
	int m; cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		bool done = false;
		for (int score = 3; score >= -3 and !done; --score) {
			for (int i = 3; i <= 5; ++i) {
				if ((score + i) % 2) {
					continue;
				}
				int w1 = (score + i) / 2;
				int w2 = i - w1;
				if (w1 < 0 or w1 > i) {
					continue;
				}
				if (w1 != 3 and w2 != 3) {
					continue;
				}
				if (dp[i][a][b][w1]) {
					done = true;
					cout << w1 << ':' << w2 << '\n';
					stack<pii> res;
					while (i) {
						auto cur = back[i][a][b][w1];
						res.push(cur);
						a -= cur.first;
						b -= cur.second;
						--i;
						if (cur.first > cur.second) {
							--w1;
						}
					}
					while (!res.empty()) {
						cout << res.top().first << ':' << res.top().second << ' ';
						res.pop();
					}
					cout << '\n';
					break;
				}
			}
		}
		if (!done) {
			cout << "Impossible\n";
		}
	}
}