#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n, t, k, d; cin >> n >> t >> k >> d;

    int time1 = (n + k - 1) / k * t;
    for (int time2 = 0; time2 < time1; ++time2) {
        int total = time2 / t * k + (time2 - d) / t * k;
        if (total >= n) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

	
	return 0;
}