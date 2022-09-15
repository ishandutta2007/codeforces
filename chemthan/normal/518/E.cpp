#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n, k;
char s[20];
int a[maxn];
bool flag[maxn];

void solve() {
	ms(a, 0); ms(flag, 0);
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		scanf("%s", s);
		if (s[0] == '?') flag[i + 1] = 1;
		else {
			bool neg = false;
			if (s[0] == '-') neg = true;
			FOR(j, neg, strlen(s)) a[i] = a[i] * 10 + s[j] - '0';
			if (neg) a[i] *= -1;
		}
	}
	FOR(i, 0, k) {
		vi pos;
		vii tmp; tmp.push_back(make_pair(INT_MIN / 2, 0));
		pos.push_back(0);
		for (int j = i; j < n; j += k) {
			if (!flag[j + 1]) {pos.push_back(sz(tmp));}
			tmp.push_back(make_pair(a[j], j));
		}
		pos.push_back(sz(tmp));
		tmp.push_back(make_pair(INT_MAX / 2, 0));
		FOR(j, 0, sz(pos) - 1) {
			int k = pos[j + 1] - pos[j] - 1;
			int u = tmp[pos[j]].first + 1;
			int v = tmp[pos[j + 1]].first - 1;
			if (v - u + 1 < k) {printf("Incorrect sequence"); return;}
			if (u >= 0) {
				int cnt = 0;
				FOR(l, pos[j] + 1, pos[j + 1]) a[tmp[l].second] = u + (cnt++);
			}
			else if (v <= 0) {
				int cnt = 0;
				FOR(l, pos[j] + 1, pos[j + 1]) a[tmp[l].second] = v - k + (++cnt);
			}
			else {
				vi w; w.push_back(0);
				FOR(l, 1, k) {
					if (sz(w) == k) break;
					if (l >= u && l <= v) w.push_back(l);
					if (sz(w) == k) break;
					if (-l >= u && -l <= v) w.push_back(-l);
				}
				sort(w.begin(), w.end()); 
				int cnt = 0;
				FOR(l, pos[j] + 1, pos[j + 1]) a[tmp[l].second] = w[cnt++];
			}
		}
	}
	FOR(i, 0, n - k) if (a[i] >= a[i + k]) {printf("Incorrect sequence"); return;}
	FOR(i, 0, n) printf("%d ", a[i]);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}