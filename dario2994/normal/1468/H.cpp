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
	int n, k, m;
	cin >> n >> k >> m;
	vector<int> a(n, false);
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		a[b-1] = true;
	}
	int nere = n-m;
	if (nere == 0) return true;
	int q = (k-1)/2;
	if (nere % (k-1) != 0) return false;
	int at = 0;
	for (int i = 0; i < n; i++) {
		//if (!a[i]) cout << i << " " << at << " " << nere-at << endl;
		if (!a[i]) at++;
		else if (at >= q and nere-at >= q) return true;
	}
	return false;
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