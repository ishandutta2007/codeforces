#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1e6 + 55;

vector <int> rem[N];
int n, L[N], R[N], cnt[N], quemarks[N], space, p[N];
char s[N];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}
 
int main() {
	scanf ("%d%s", &n, s + 1);
	int q = 0;
	rep(i, 1, n) {
		L[i] = q;
		if (s[i] != '?')
			q = i;
	}
	q = n + 1;
	per(i, 1, n) {
		R[i] = q;
		if (s[i] != '?')
			q = i;
	}
	rep(i, 1, n)
		if (s[i] == '?' && 1 <= L[i] && R[i] <= n && s[L[i]] == s[R[i]])
			s[i] = s[L[i]];
	s[0] = '#';
	rep(i, 1, n) {
		if (s[i] == '?')
			quemarks[space]++;
		else {
			if (s[i - 1] != s[i]) space++;
			cnt[space]++;
		}
	}
	rep(i, 1, space) {
		p[i] = i;
		rem[cnt[i] + quemarks[i - 1] + quemarks[i] + 1].pb(i);
	}
	p[space + 1] = space + 1;
	rep(i, 1, n) {
		if (!space) {
			printf ("%d\n", n / i);
			continue;
		}
		for (auto x : rem[i])
			p[x] = x + 1;
		int prv = -1, j = find(1), qq = 0, res = 0;
		while (j <= space) {
			if (prv + 1 < j) qq = quemarks[j - 1];
			int val = qq + cnt[j] + quemarks[j];
			res += val / i;
			qq = min(quemarks[j], val % i);
			prv = j;
			j = find(j + 1);
		}
		printf ("%d ", res);
	}
	
	return 0;
}