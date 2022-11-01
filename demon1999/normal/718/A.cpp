#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

int n, t;
string s;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> t;
	cin >> s;
	int num = n;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		if (ok && s[i] >= '5') {
			num = i;
			break;
		}
		if (s[i] == '.')
			ok = true;
	}
	if (num == n) {
		cout << s;
		re 0;
	}
	//cout << "Im coco\n";
	string ans = "";
	ok = false;
	bool okk = false;
	for (int j = num; j >= 0; j--) {
		if (s[j] == '.') {
			ok = true;
		}
		if (s[j] - '0' >= 10) {
			s[j] = char(s[j] - 10);
			if (j)
				s[j - 1] += 1;
			else
				okk = true;
		}
		if (t == 0) ok = true;
		if (ok) {
			ans += s[j];
			continue;
		}
		if (s[j] >= '5') {
			t--;
			if (s[j - 1] == '.') {
				s[j - 2] = char(s[j - 2] + 1);
			}
			else
				s[j - 1] = char(s[j - 1] + 1);
		}
		else {
			ok = true; 
			ans += s[j];
		}
	}
	if (okk) ans += '1';
	reverse(ans.begin(), ans.end());
	if (ans[sz(ans) - 1] == '.')
		ans.erase(sz(ans) - 1, 1);
	cout << ans;
	re 0;
}