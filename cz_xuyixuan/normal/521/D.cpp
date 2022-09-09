#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 1e9 + 7;
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
int k, n, m, tot;
int Maxone[MAXN]; ll v[MAXN];
vector <pair <int, int>> inc[MAXN];
pair <pair <ll, ll>, int> a[MAXN];
int opt[MAXN], who[MAXN], w[MAXN];
pair <ll, ll> prod(ll a, ll b) {
	pair <ll, ll> res = make_pair(a / P * b + b / P * a - (a / P) * (b / P) * P, (a % P) * (b % P));
	res.first += res.second / P;
	res.second %= P;
	return res;
}
bool cmp(pair <pair <ll, ll>, int> a, pair <pair <ll, ll>, int> b) {
	return prod(a.first.first, b.first.second) > prod(a.first.second, b.first.first);
}
int main() {
	read(k), read(n), read(m);
	for (int i = 1; i <= k; i++)
		read(v[i]);
	for (int i = 1; i <= n; i++) {
		read(opt[i]), read(who[i]), read(w[i]);
		if (opt[i] == 1 && w[i] > w[Maxone[who[i]]]) Maxone[who[i]] = i;
		if (opt[i] == 2) inc[who[i]].emplace_back(w[i], i);
		if (opt[i] == 3) a[++tot] = make_pair(make_pair(w[i], 1), i);
	}
	for (int i = 1; i <= k; i++)
		if (w[Maxone[i]] > v[i]) inc[i].emplace_back(w[Maxone[i]] - v[i], Maxone[i]);
	for (int i = 1; i <= k; i++) {
		sort(inc[i].begin(), inc[i].end());
		reverse(inc[i].begin(), inc[i].end());
		for (auto x : inc[i]) {
			a[++tot] = make_pair(make_pair(v[i] + x.first, v[i]), x.second);
			v[i] += x.first;
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	vector <int> ans;
	for (int i = 1; i <= min(m, tot); i++)
		ans.push_back(a[i].second);
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end(), [&] (int x, int y) {return opt[x] < opt[y]; });
	for (auto x : ans) printf("%d ", x);
	return 0;
}