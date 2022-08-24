#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 307, T = 200007;

const int K = N*T;
int cnt[2*K+1];
int was[T];
int sz = 0;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	ll ans = 0;	
	for (int i = 1; i <= N; ++i) {
		int sum = 0;
		for (int j = 0; j <= s.size(); ++j) {
			int Q = i*sum - j;
			was[sz++] = Q;
			cnt[Q+K]++;
			if (j==s.size()) break;
			sum += (s[j] == '1');
		}
		for (int j = 0; j < sz; ++j) {
			ans += ((ll) cnt[was[j]+K] * (cnt[was[j]+K] - 1)) / 2;
			cnt[was[j]+K] = 0;
		}
		sz=0;
	}

	vector<int> ones;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1') ones.push_back(i);
	for (int l = 0; l < ones.size(); ++l) {
		for (int r = l; r < ones.size() && (ll) (r-l+1) * (N+1) <= (ll) s.size(); ++r) {
			int A, B;
			if (l != 0) A = ones[l] - ones[l-1] - 1;
			else A = ones[l];
			if (r+1 != ones.size()) B = ones[r+1] - ones[r] - 1;
			else B = s.size() - ones[r] - 1;
			for (int take = 0; take <= A; ++take) {
				int len = ones[r] - ones[l] + 1 + take;
				int rem = len % (r-l+1);
				if (rem != 0) rem = r-l+1-rem;

				int nxt = max((r-l+1) * (N+1) - len, rem);
				B -= nxt;
				if (B >= 0) ans += (B / (r-l+1)) + 1;
				B += nxt;
			}
		}
	}

	cout << ans;
}