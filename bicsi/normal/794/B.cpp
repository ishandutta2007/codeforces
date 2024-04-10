#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n; double h;
    cin >> n >> h;

    cout << fixed << setprecision(12);
    for (int i = 1; i < n; ++i) {
        cout << h * sqrt(1.0 * i / n) << " ";
    }
    cout << endl;

	return 0;
}