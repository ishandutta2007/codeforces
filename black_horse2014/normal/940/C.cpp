#include <bits/stdc++.h>
using namespace std;

char s[110000];
int chk[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k; cin >> n >> k;
	scanf("%s", s);
	for (int i = 0; i < n; i++) chk[s[i] - 'a'] = 1;
	vector<int> V;
	for (int i = 0; i < 26; i++) if (chk[i]) V.push_back(i);
	if (k > n) {
		for (int i = 0; i < k; i++) {
			if (i < n) putchar(s[i]);
			else putchar(V[0] + 'a');
		}
		return puts(""), 0;
	}
	for (int i = k - 1; i >= 0; i--) {
		if (s[i] - 'a' < V.back()) {
			s[i] = 'a' + *upper_bound(V.begin(), V.end(), s[i] - 'a');
			for (int j = i + 1; j < k; j++) s[j] = V[0] + 'a';
			break;
		}
	}
	s[k] = 0;
	puts(s);
	return 0;
}