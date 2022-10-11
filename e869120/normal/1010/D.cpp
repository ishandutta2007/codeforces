#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

int n, par[1000009], val[1000009], rem[1000009]; tuple<string, int, int>x[1000009];

int dfs(int pos) {
	if (get<0>(x[pos]) == "IN") {
		return val[pos];
	}
	if (get<0>(x[pos]) == "NOT") {
		int v1 = dfs(get<1>(x[pos]));
		val[pos] = (1 ^ v1);
	}
	if (get<0>(x[pos]) == "AND") {
		int v1 = dfs(get<1>(x[pos]));
		int v2 = dfs(get<2>(x[pos]));
		val[pos] = (v1&v2);
	}
	if (get<0>(x[pos]) == "OR") {
		int v1 = dfs(get<1>(x[pos]));
		int v2 = dfs(get<2>(x[pos]));
		val[pos] = (v1|v2);
	}
	if (get<0>(x[pos]) == "XOR") {
		int v1 = dfs(get<1>(x[pos]));
		int v2 = dfs(get<2>(x[pos]));
		val[pos] = (v1^v2);
	}
	return val[pos];
}
void dfs2(int pos) {
	if (pos == 1) { rem[pos] = (1 ^ val[pos]); }
	else {
		int r = par[pos];
		if (get<0>(x[r]) == "NOT") {
			rem[pos] = rem[r];
		}
		if (get<0>(x[r]) == "AND") {
			int res = 1;
			if (get<1>(x[r]) != pos) res &= val[get<1>(x[r])]; else res &= (1 ^ val[get<1>(x[r])]);
			if (get<2>(x[r]) != pos) res &= val[get<2>(x[r])]; else res &= (1 ^ val[get<2>(x[r])]);
			if (res == val[r]) rem[pos] = val[1];
			else rem[pos] = rem[r];
		}
		if (get<0>(x[r]) == "OR") {
			int res = 0;
			if (get<1>(x[r]) != pos) res |= val[get<1>(x[r])]; else res |= (1 ^ val[get<1>(x[r])]);
			if (get<2>(x[r]) != pos) res |= val[get<2>(x[r])]; else res |= (1 ^ val[get<2>(x[r])]);
			if (res == val[r]) rem[pos] = val[1];
			else rem[pos] = rem[r];
		}
		if (get<0>(x[r]) == "XOR") {
			int res = 0;
			if (get<1>(x[r]) != pos) res ^= val[get<1>(x[r])]; else res ^= (1 ^ val[get<1>(x[r])]);
			if (get<2>(x[r]) != pos) res ^= val[get<2>(x[r])]; else res ^= (1 ^ val[get<2>(x[r])]);
			if (res == val[r]) rem[pos] = val[1];
			else rem[pos] = rem[r];
		}
	}
	if (get<0>(x[pos]) != "IN") dfs2(get<1>(x[pos]));
	if (get<0>(x[pos]) == "AND" || get<0>(x[pos]) == "OR" || get<0>(x[pos]) == "XOR") dfs2(get<2>(x[pos]));
}

int main() {
	cin >> n; par[1] = -1; vector<int>vec;
	for (int i = 1; i <= n; i++) {
		string s; int px, py;
		cin >> s;
		if (s == "IN") { cin >> px; val[i] = px; vec.push_back(i); x[i] = make_tuple(s, -1, -1); }
		if (s == "NOT") { cin >> px; x[i] = make_tuple(s, px, -1); par[px] = i; }
		if (s == "AND" || s == "OR" || s == "XOR") { cin >> px >> py; x[i] = make_tuple(s, px, py); par[px] = i; par[py] = i; }
	}
	dfs(1);
	dfs2(1);
	for (int i = 0; i < vec.size(); i++) cout << rem[vec[i]]; cout << endl;
	return 0;
}