#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif


bool solve() {
	vector<int> c(3);
	vector<int> a(5);
	for (int i = 0; i < 3; i++) cin >> c[i];
	for (int i = 0; i < 5; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) {
		if (a[i] > c[i]) return false;
		c[i] -= a[i];
	}
	a[3] -= min(c[0], a[3]);
	a[4] -= min(c[1], a[4]);
	if (a[3] + a[4] > c[2]) return false;
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}