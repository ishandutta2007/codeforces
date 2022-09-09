#include<bits/stdc++.h>
using namespace std;
const int MAXN = 155;
const int INF  = 2e9;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct vec {bitset <MAXN> a; };
struct mat {bitset <MAXN> r[MAXN], c[MAXN]; };
int n, m;
vec Veccipher() {
	vec ans; ans.a.reset();
	return ans;
}
mat Matcipher() {
	mat ans;
	for (int i = 1; i <= n; i++) {
		ans.r[i].reset();
		ans.c[i].reset();
	}
	ans.r[n].set(n);
	ans.c[n].set(n);
	return ans;
}
mat unit() {
	mat ans;
	for (int i = 1; i <= n; i++) {
		ans.r[i].reset();
		ans.c[i].reset();
		ans.r[i].set(i);
		ans.c[i].set(i);
	}
	return ans;
}
vec operator * (vec a, mat b) {
	vec ans;
	for (int i = 1; i <= n; i++)
		if ((a.a & b.c[i]).count() != 0) ans.a[i] = true;
		else ans.a[i] = false;
	return ans;
}
mat operator * (mat a, mat b) {
	mat ans;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		if ((a.r[i] & b.c[j]).count() != 0) ans.r[i][j] = ans.c[j][i] = true;
		else ans.r[i][j] = ans.c[j][i] = false;
	}
	return ans;
}
mat power(mat x, int y) {
	if (y == 0) return unit();
	mat tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp;
	else return tmp * tmp * x;
}
pair <pair <int, int>, int> e[MAXN];
bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y) {
	return x.second < y.second;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(e[i].first.first);
		read(e[i].first.second);
		read(e[i].second);
	}
	sort(e + 1, e + m + 1, cmp);
	e[m + 1] = make_pair(make_pair(1, 1), INF);
	vec now = Veccipher(); now.a[1] = true;
	mat tmp = Matcipher();
	for (int i = 1; i <= m + 1; i++) {
		int cnt = e[i].second - e[i - 1].second;
		vec tnp = now * power(tmp, cnt);
		if (tnp.a[n]) {
			int ans = e[i - 1].second;
			while (now.a[n] == 0) {
				ans++;
				now = now * tmp;
			}
			cout << ans << endl;
			return 0;
		}
		int x = e[i].first.first, y = e[i].first.second;
		tmp.r[x][y] = tmp.c[y][x] = true; now = tnp;
	}
	puts("Impossible");
	return 0;
}