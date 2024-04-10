#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int a, b, c;
    cin >> b >> a >> c;

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > a && x < c)
            ans += 1;
    }
    cout << ans << endl;
	
	return 0;
}