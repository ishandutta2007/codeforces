#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, int> last;
map<string, int> curr;

int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int n;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		++last[s];
	}
	for(int i = 0; i < n; ++i) {
		cin >> s;
		++curr[s];
	}
	int ans = 0;

	// len 1
	int v1[3] = {last["S"], last["M"], last["L"]};
	int v2[3] = {curr["S"], curr["M"], curr["L"]};
	for(int i = 0; i < 3; ++i) {
		ans += abs(v1[i] - v2[i]);
	}
	ans /= 2;

	// other
	for(string p : {"X", "XX", "XXX"}) {
		string a = p + "S";
		string b = p + "L";
		ans += abs(last[a]-curr[a]);
	}
	cout << ans << "\n";
}