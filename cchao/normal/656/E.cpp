#include <bits/stdc++.h>
using namespace std;

int N;
int ni() {
	int x;
	cin >> x;
	return x;
}

template<typename T>
vector<T> ap(vector<T> a, T x) {
	a.push_back(x);
	return a;
}

vector<int> c(int n) {
	vector<int> ret = n == 0 ? vector<int>() : c(n - 1);
	return n == 0 ? ret : ap(ret, ni());
}

vector<vector<int>> r(int n) {
	vector<vector<int>> ret = n == 0 ? vector<vector<int>>() : r(n - 1);
	return n == 0 ? ret : ap(ret, c(N));
}

vector<array<int, 3>> gen(int i, int j, int k, int n) {
	vector<array<int, 3>> ret;
	array<int, 3> t = {i, j, k};

	k++;

	j += k / n;
	k %= n;

	i += j / n;
	j %= n;


	return i == n ? ap(ret, t) : ap(gen(i, j, k, n), t);
}


int work(vector<vector<int>> &g, vector<array<int, 3>> xd) {
	int i = xd.back()[0];
	int j = xd.back()[1];
	int k = xd.back()[2];
	g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
	xd.pop_back();
	return xd.empty() ? 0 : work(g, xd);
}
int ans = 0;
int work2(vector<vector<int>> &g, vector<array<int, 3>> xd) {
	int i = xd.back()[0];
	int j = xd.back()[1];
	int k = xd.back()[2];
	ans = max(ans, g[i][j]);
	xd.pop_back();
	return xd.empty() ? 0 : work2(g, xd);
}

int main() {
	int n;
	cin >> n;
	N = n;
	auto g = r(n);

	auto xd = gen(0, 0, 0, n);
	work(g, xd);

	work2(g, xd);
	cout << ans << endl;
	return 0;
}