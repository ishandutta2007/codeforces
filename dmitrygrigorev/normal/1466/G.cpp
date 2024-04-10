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
const int N = 1e6+7;

int pw[N];
int rw[N];

string construct(string s, string t) {

	string cur = s;
	int u = 0;

	while (cur.size() < N && u < t.size()) {
		auto Q = cur;
		Q += t[u];

		for (int i = 0; i < cur.size(); ++i) {
			if (Q.size() < N) {
				Q += cur[i];
			}
		}

		u++;
		cur = Q;

	}

	return cur;


}

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

const int START = 25;

int pcnt[N][26];

const int INF = 1e9;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	pw[0] = 1;
	rw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = ((ll) pw[i-1] * 2) % mod;
		rw[i] = ((ll) rw[i-1] * ((mod+1)/2)) % mod;
	}

	int n, q;
	cin >> n >> q;

	string s, t;
	cin >> s >> t;

	string head = construct(s, t);
	reverse(all(s));
	string tail = construct(s, t);
	reverse(all(tail));
	reverse(all(s));

	vector<int> cnt(26, 0);
	for (int j = START + 1; j <= t.size(); ++j) {

		for (int e = 0; e < 26; ++e) pcnt[j][e] = pcnt[j-1][e];

		int num = pw[t.size() - j];
		pcnt[j][t[j-1] - 'a'] += num;
		if (pcnt[j][t[j-1] - 'a'] >= mod) pcnt[j][t[j-1] - 'a'] -= mod;
	}

	for (int i = 0; i < q; ++i) {
		int index;
		cin >> index;

		string k;
		cin >> k;

		int ans = 0;
		for (int j = 0; j + k.size() <= s.size(); ++j) {
			bool can = true;
			for (int e = 0; e < k.size(); ++e) {
				if (k[e] != s[j + e]) can = false;
			}
			if (can) ans += pw[t.size() - (t.size() - index)];
			if (ans >= mod) ans -= mod;
		}

		int piece = s.size();


		for (int j = 1; j <= min({START, (int) t.size(), index}); ++j) {

			int sindex = 0;

			string string_to_check = "";
			for (int e = 0; e < min({(int) k.size(), (int) tail.size(), piece}); ++e) {
				string_to_check += tail[tail.size() - 1 - e];
				sindex++;
			}
			reverse(all(string_to_check));

			string_to_check += t[j - 1];
			for (int e = 0; e < min({(int) k.size(), (int) head.size(), piece}); ++e) string_to_check += head[e];

			//cout << string_to_check << endl;


			string forz = k + '#' + string_to_check;
			sindex += (k.size()+1);

			auto Z = z_function(forz);

			for (int e = k.size() + 1; e+k.size() <= forz.size(); ++e) {
				int L = e, R = e + k.size() - 1;
				if (sindex >= L && sindex <= R && Z[e] == k.size()) {
					ans += pw[t.size() - j - (t.size() - index)];
					if (ans >= mod) ans -= mod;
				}
			}

			piece = min(INF, piece * 2 + 1);

		}


		string phead, ptail;
		for (int i = 0; i < min(head.size(), k.size()); ++i) phead += head[i];
		for (int i = 0; i < min(tail.size(), k.size()); ++i) ptail += tail[tail.size() - i - 1];

		reverse(all(ptail));

		string A = phead + '#' + k;
		string rt = ptail, rs = k;
		reverse(all(rt)), reverse(all(rs));

		string B = rt + '#' + rs;

		//cout << head << " " << tail << endl;

		auto AZ = z_function(A), BZ = z_function(B);

		for (int take = 0; take < k.size(); ++take) {
			bool can = true;
			if (take != 0 && BZ[BZ.size() - take] != take) {
				can = false;
			}
			int W = k.size() - 1 - take;
			if (W != 0 && AZ[AZ.size() - W] != W) can = false;
			if (can) {
				//cout << take << endl;
				ans += (((ll) pcnt[index][k[take] - 'a'] * rw[t.size() - index]) % mod);
				if (ans >= mod) ans -= mod;
			}
		}

		cout << ans << '\n';



	}



}