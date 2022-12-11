#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int)s.size();
	vi V(n,0);
	for (int i = 0; i < n; ++i) {
		if (s[i] != 'a') V[i] = 1;
		if (i) V[i] += V[i-1];
	}
	int tot = V[n-1];
	if (tot%2) {
		cout << ":(\n";
		return 0;
	}
	if (tot == 0) {
		cout << s << '\n';
		return 0;
	}
	int j = 0;
	while (V[j] <= tot/2) ++j;
	for (int i = 0; j < n; ++j, ++i) {
		while (s[i] == 'a') ++i;
		if (s[j] == 'a' or s[j] != s[i]) {
			cout << ":(\n";
			return 0;
		}
	}
	j = 0;
	while (V[j] <= tot/2) cout << s[j++];
	cout << '\n';
}