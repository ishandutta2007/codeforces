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

void solve() {
	int x;
	cin >> x;
	string s;
	cin >> s;
	int len = s.size();

	for (int i=0; i < x; ++i) {
		if (s.size() < x) {
			int L = i+1, R = s.size() - 1;
			for (int take=0; take < (s[i] - '1'); ++take) {
				for (int j = L; j <= R; ++j) {
					s += s[j];
				}
			}
			len = s.size();
		}
		else{
			int suff = (len - i - 1 + mod) % mod;
			suff = ((ll) suff * (s[i] - '1')) % mod;
			//cout << i << " " << s.size() << " " << suff << endl;
			len = (len+suff) % mod;
			//cout << "===== " << i << " " << len << endl;
		}
	}
	cout << len << "\n";

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i=0; i < t; ++i) solve();

}