#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int sum[200007][26];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < s.size(); ++j) {
			sum[j+1][i] = sum[j][i] + (s[j] - 'a' == i);
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		if (l==r) {
			cout << "Yes\n";
			continue;
		}
		int cnt = 0;

		for (int j = 0; j < 26; ++j) {
			int t = sum[r][j] - sum[l-1][j];
			if (t > 0) {
				cnt++;
			}
		}
		if (cnt==1) cout << "No\n";
		else if (cnt == 2) {
			if (s[l-1] != s[r-1]) {
				cout << "Yes\n";
			}
			else cout << "No\n";
		}	
		else cout << "Yes\n";
	}

}