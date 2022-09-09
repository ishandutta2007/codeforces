#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
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
bool used[MAXN];
int a[MAXN], s[MAXN], f[MAXN];
int query(vector <int> points, int pos) {
	cout << 1 << endl;
	cout << 1 << endl;
	cout << points.size() << endl;
	for (auto x : points) cout << x << ' ';
	cout << endl;
	cout << pos << endl;
	int res; read(res);
	return res;
}
int find(vector <int> points, int pos) {
	if (points.size() == 1) return points.back();
	vector <int> a, b;
	for (unsigned i = 0; i < points.size(); i++)
		if (i & 1) a.push_back(points[i]);
		else b.push_back(points[i]);
	if (query(a, pos)) return find(a, pos);
	else return find(b, pos);
}
void work(vector <int> points, int pos) {
	while (points.size() > 0) {
		int tmp = query(points, pos);
		if (tmp == 0) return;
		tmp = find(points, pos);
		used[tmp] = true, f[tmp] = pos;
		sort(points.begin(), points.end(), [&] (int x, int y) {return (x == tmp) < (y == tmp); });
		points.pop_back();
	}
}
int main() {
	int n; read(n);
	if (n == 2) {
		cout << "ANSWER" << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	s[1] = n;
	for (int i = 2; i <= n; i++) {
		cout << 1 << endl;
		cout << 1 << endl;
		cout << n - 2 << endl;
		for (int j = 2; j <= n; j++)
			if (i != j) cout << j << ' ';
		cout << endl;
		cout << i << endl;
		read(s[i]);
	}
	for (int i = 1; i <= n; i++)
		a[i] = i;
	sort(a + 1, a + n + 1, [&] (int x, int y) {return s[x] < s[y]; });
	for (int i = 1; i <= n - 1; i++) {
		vector <int> points;
		for (int j = 1; j <= i - 1; j++)
			if (!used[a[j]]) points.push_back(a[j]);
		work(points, a[i]);
	}
	for (int i = 2; i <= n; i++)
		if (!used[i]) f[i] = 1;
	cout << "ANSWER" << endl;
	for (int i = 2; i <= n; i++)
		cout << f[i] << ' ' << i << endl;
	return 0;
}