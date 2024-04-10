#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int n, w, c, a[100]; vector<tuple<int, int, int>>E;
int main() {
	cin >> n >> w; for (int i = 0; i < n; i++) { cin >> a[i]; E.push_back(make_tuple(a[i], (a[i] + 1) / 2, i)); c += (a[i] + 1) / 2; }
	sort(E.begin(), E.end());
	for (int i = E.size() - 1; i >= 0; i--) {
		while (get<0>(E[i]) > get<1>(E[i]) && c < w) { get<1>(E[i])++; c++; }
	}
	if (c != w)cout << "-1" << endl;
	else {
		for (int i = 0; i < E.size(); i++)a[get<2>(E[i])] = get<1>(E[i]);
		for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << a[i]; } cout << endl;
	}
	return 0;
}