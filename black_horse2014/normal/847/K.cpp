#include<bits/stdc++.h>
using namespace std;
map<string, int> M;
const int N = 777;
int u[N], v[N], c[N];
int value[N][N];

int hn = 0;
int Hash(string s) {
	if (M.count(s)) return M[s];
	return M[s] = ++hn;
}

int main() {
	int n, a, b, k, f; cin >> n >> a >> b >> k >> f;
	int prv = -1;
	int all = 0;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s, u[i] = Hash(s);
		cin >> s, v[i] = Hash(s);
		if (u[i] == v[i]) continue;
		if (prv == u[i]) c[i] = b;
		else c[i] = a;
		all += c[i];
		value[min(u[i], v[i])][max(u[i], v[i])] += c[i];
		prv = v[i];
	}
	vector<int> vec;
	for (int i = 1; i <= hn; i ++) {
		for (int j = 1; j <= hn; j ++) {
			if (value[i][j]) vec.push_back(value[i][j]);
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < min(k, (int)vec.size()); i ++) {
		if (vec[i] > f) all -= (vec[i] - f);
		else break;
	}
	cout << all << endl;
	return 0;
}