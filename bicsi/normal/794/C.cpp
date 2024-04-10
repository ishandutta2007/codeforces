#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    a.resize((n + 1) / 2);
    b.resize(n / 2);

    string ans(n, '?');
    int i = 0, j = 0, turn = 0, e = n - 1, s = 0;
    for (int it = 0; it < n; ++it) {
        if (turn == 0) {
            if (j == b.size() || a[i] < b[j]) {
                ans[s++] = a[i++];
            } else {
                ans[e--] = a.back();
                a.pop_back();
            }
        } else {
            if (i == a.size() || a[i] < b[j]) {
                ans[s++] = b[j++];
            } else {
                ans[e--] = b.back();
                b.pop_back();
            }
        }

        turn = !turn;
        // cerr << ans << endl;
    }


    for (auto x : ans)
        assert(x != '?');
    
    cout << ans << endl;
	
	return 0;
}