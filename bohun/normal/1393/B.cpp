#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	

const int N = 100100;

int n;
int cnt[N];

int main() {	
	scanf ("%d", &n);
	rep(i, 1, n) {
		int a;
		scanf ("%d", &a);
		cnt[a]++;
	}
	multiset <int> S;
	rep(i, 1, N - 1) S.insert(cnt[i]);
	int q;
	scanf ("%d", &q);
	while (q--) {
		char c;
		int a;
		scanf (" %c", &c);
		scanf ("%d", &a);
		if (c == '+') {
			S.erase(S.find(cnt[a]));
			cnt[a]++;
			S.insert(cnt[a]);
		}
		else {
			S.erase(S.find(cnt[a]));
			cnt[a]--;
			S.insert(cnt[a]);
		}
		auto it = S.end();
		--it;
		int d = 0, bad = 0;
		if (*it < 4) bad = true;
		else {
			d += (*it - 4) / 2;
			--it;
			d += *it / 2;
			--it;
			d += *it / 2;
		}
		if (d < 2) bad = true;
		printf (bad ? "NO\n" : "YES\n");
	}
	
	return 0;
}