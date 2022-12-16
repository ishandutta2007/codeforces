#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	int h = 1;
	ll ans = 0;
	vector<int> a(M);
	for(int& ii : a) cin >> ii;
	for(int ai : a) {
		if (ai > h) ans += ai-h;
		if (ai < h) ans += N + ai - h;
		h = ai;
	}
	cout << ans << endl;

	return 0;
}