#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 2e5 + 111;

char s[nax];

int l, r, q;

int p[nax][26];
int b[26];

void tak() {
	printf ("Yes\n");
}

void nie() {
	printf ("No\n");
}

int main() {
	scanf ("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		b[s[i] - 'a']++;
		for (int j = 0; j < 26; ++j)
			p[i][j] = b[j];
	}
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &l, &r);
		if (l == r) {
			tak();
			continue;
		}
		if (s[l] != s[r]) {
			tak();
			continue;
		}
		int e = 0;
		for (int i = 0; i < 26; ++i)
			e += ((p[r][i] - p[l - 1][i]) > 0);
		if (3 <= e) tak();
		else nie();
	}


	return 0;
}