#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n, s, x, r; vector<pair<int, int>>V;
int main() {
	srand((unsigned)time(NULL));
	cin >> n >> s >> x;
	cout << "? " << s << endl;
	int H1, H2; cin >> H1 >> H2; V.push_back(make_pair(H1, s));
	for (int i = 1; i <= 999; i++) {
		int G = ((i*n) / 999) % n; G++;
		cout << "? " << G << endl;
		int ans, ans2; cin >> ans >> ans2;
		V.push_back(make_pair(ans, G));
	}
	r = s;
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		if (V[i].first < x)r = V[i].second;
	}
	int cx = r; bool OK = false;
	for (int i = 1; i <= 998; i++) {
		cout << "? " << cx << endl;
		int ans, ans2; cin >> ans >> ans2;
		if (ans >= x) { cout << "! " << ans << endl; OK = true; break; }
		if (ans2 == -1) { cout << "! -1" << endl; OK = true; break; }
		cx = ans2;
	}
	if (OK == false)cout << "! -1" << endl;
	return 0;
}