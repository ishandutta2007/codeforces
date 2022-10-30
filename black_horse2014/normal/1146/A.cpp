#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    string s; cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (s[i] == 'a');
    if (2 * cnt - 1 <= n) {
        cout << 2 * cnt - 1 << endl;
    } else {
        cout << n << endl;
    }
    return 0;
}