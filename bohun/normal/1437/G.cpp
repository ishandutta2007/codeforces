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
 
const int N = 3e5 + 5;
 
int n, qq, val[N], a, b, c, sus[N], to2[N];
multiset<int> setik[N];
 
char s[N];
int cnt, to[N][26], fail[N], where[N];
 
void add(int id) {
	int m = strlen(s + 1), v = 0;
	rep(j, 1, m) {
		int c = s[j] - 'a';
		if (!to[v][c]) to[v][c] = ++cnt;
		v = to[v][c];
	}
	where[id] = v;
	val[v] = 0;
}
 
queue <int> q;
void build() {
	q.push(0);
	while (sz(q)) {
		int v = q.front();
		q.pop();
		to2[v] = val[fail[v]] >= 0 ? fail[v] : to2[fail[v]];
		rep(c, 0, 25) {
			int &nxt = to[v][c];
			if (nxt) {
				fail[nxt] = v == 0 ? 0 : to[fail[v]][c];
				q.push(nxt);
			}
			else
				nxt = to[fail[v]][c];
		}
	}
}
 
int main() {
	memset(val, -1, sizeof val);
	scanf ("%d%d", &n, &qq);
	rep(i, 1, n) {
		scanf ("%s", s + 1);
		add(i);
		setik[where[i]].insert(0);
	}
	build();
	while (qq--) {
		scanf ("%d", &a);
		if (a == 1) {
			scanf ("%d%d", &b, &c);
			int id = where[b];
			setik[id].erase(setik[id].find(sus[b]));
			setik[id].insert(c);
			val[id] = *setik[id].rbegin();
			sus[b] = c;
		}
		else {
			scanf ("%s", s + 1);
			int m = strlen(s + 1), v = 0, res = -1;
			rep(i, 1, m) {
				v = to[v][s[i] - 'a'];
				for (int j = v; j != 0; j = to2[j])
					res = max(res, val[j]);
			}
			printf ("%d\n", res);
		}
	}
		
}