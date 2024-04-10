#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int n, x[100009], y[100009], bit[131077], power[100009], mod = 1000000009; bool used[100009], u2[100009]; vector<tuple<int, int, int>>Z; vector<int>fd[100009], fu[100009];
void add(int pos, int x) {
	x += 0;
	while (pos <= 131072) { bit[pos] += x; pos += (pos&-pos); }
}
int sum(int p) {
	int s = 0;
	while (p >= 1) { s += bit[p]; p -= (p&-p); }
	return s;
}
int minv() {
	int F = 0;
	for (int i = 17; i >= 0; i--) {
		if (sum(F + (1 << i)) == 0)F += (1 << i);
	}
	return F + 1;
}
int maxv() {
	int F = 0;
	for (int i = 17; i >= 0; i--) {
		if (sum(131072) - sum(F + (1 << i)) >= 1)F += (1 << i);
	}
	return F + 1;
}
bool moves(int p) {
	for (int i : fu[p]) {
		if (used[i] == true)continue;
		int H = 0;
		for (int j : fd[i]) {
			if (used[j] == true)continue;
			H++;
		}
		if (H == 1)return false;
	}
	return true;
}
int main() {
	cin >> n;
	power[0] = 1; for (int i = 1; i <= n; i++)power[i] = (1LL * power[i - 1] * n) % mod;
	for (int i = 1; i <= n; i++) { cin >> x[i] >> y[i]; Z.push_back(make_tuple(x[i], y[i], i)); }
	sort(Z.begin(), Z.end());
	for (int i = 1; i <= n; i++) {
		int pos1;
		pos1 = lower_bound(Z.begin(), Z.end(), make_tuple(x[i] - 1, y[i] - 1, 0)) - Z.begin(); if (pos1 < Z.size() && get<0>(Z[pos1]) == x[i] - 1 && get<1>(Z[pos1]) == y[i] - 1)fd[i].push_back(get<2>(Z[pos1]));
		pos1 = lower_bound(Z.begin(), Z.end(), make_tuple(x[i] - 0, y[i] - 1, 0)) - Z.begin(); if (pos1 < Z.size() && get<0>(Z[pos1]) == x[i] - 0 && get<1>(Z[pos1]) == y[i] - 1)fd[i].push_back(get<2>(Z[pos1]));
		pos1 = lower_bound(Z.begin(), Z.end(), make_tuple(x[i] + 1, y[i] - 1, 0)) - Z.begin(); if (pos1 < Z.size() && get<0>(Z[pos1]) == x[i] + 1 && get<1>(Z[pos1]) == y[i] - 1)fd[i].push_back(get<2>(Z[pos1]));
		pos1 = lower_bound(Z.begin(), Z.end(), make_tuple(x[i] - 1, y[i] + 1, 0)) - Z.begin(); if (pos1 < Z.size() && get<0>(Z[pos1]) == x[i] - 1 && get<1>(Z[pos1]) == y[i] + 1)fu[i].push_back(get<2>(Z[pos1]));
		pos1 = lower_bound(Z.begin(), Z.end(), make_tuple(x[i] - 0, y[i] + 1, 0)) - Z.begin(); if (pos1 < Z.size() && get<0>(Z[pos1]) == x[i] - 0 && get<1>(Z[pos1]) == y[i] + 1)fu[i].push_back(get<2>(Z[pos1]));
		pos1 = lower_bound(Z.begin(), Z.end(), make_tuple(x[i] + 1, y[i] + 1, 0)) - Z.begin(); if (pos1 < Z.size() && get<0>(Z[pos1]) == x[i] + 1 && get<1>(Z[pos1]) == y[i] + 1)fu[i].push_back(get<2>(Z[pos1]));
	}
	for (int i = 1; i <= n; i++) {
		if (moves(i) == true) { add(i, 1); u2[i] = true; }
	}
	long long ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		int G = 0; if ((n - i) % 2 == 1)G = maxv(); else G = minv();
		ret += 1LL * power[i] * (G - 1); ret %= mod;
		add(G, -1); used[G] = true;
		for (int j : fd[G]) {
			if (used[j] == true)continue;
			if (moves(j) == true && u2[j] == false) { add(j, 1); u2[j] = true; }
			if (moves(j) == false && u2[j] == true) { add(j, -1); u2[j] = false; }
		}
		for (int j : fu[G]) {
			for (int k : fd[j]) {
				if (used[k] == true)continue;
				if (moves(k) == true && u2[k] == false) { add(k, 1); u2[k] = true; }
				if (moves(k) == false && u2[k] == true) { add(k, -1); u2[k] = false; }
			}
		}
	}
	cout << ret << endl;
	return 0;
}