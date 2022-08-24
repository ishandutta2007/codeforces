#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

const int N = 1000007;

int dp[N];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	string t = "1";
	for (auto x : s) t.pb(x);
	t.pb('1');

	s = t;

	vector<int> sizes;
	int now = 0;

	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '0') now++;
		else {
			sizes.pb(now);
			now = 0;
		}
	}

	if (sizes.size() == 1) {
		cout << sizes[0];
		exit(0);
	}

	dp[1] = sizes[0] + 1;

	vector<int> nxt(sizes.size());
	vector<pair<int, int> > elements;

	for (int i = sizes.size() - 1; i >= 0; i--) {
		while (elements.size()) {
			if (elements.back().first <= sizes[i]) elements.pop_back();
			else break;
		}

		if (elements.size()) {
			nxt[i] = elements.back().second;
		}
		else nxt[i] = -1;

		elements.pb(mp(sizes[i], i));
	}

	for (int i = 1; i < sizes.size(); ++i) {

		int now = i;
		int last = -1;

		while (now+1 < sizes.size()) {

			int kek = ((ll) (sizes[now] - last) * dp[i]) % mod;
			dp[now+1] = (dp[now+1] + kek) % mod;

			last = sizes[now];
			if (nxt[now] == -1) break;
			now = nxt[now];
		}

		int kek = ((ll) (sizes.back()) * dp[i]) % mod;

		dp[sizes.size()] = (dp[sizes.size()] + kek) % mod;

		

	}

	int ans = 0;
	for (int i = 1; i <= sizes.size(); ++i) {
		ans = (ans + dp[i]) % mod;
	}

	cout << ans;




}