#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> s(m);
        for (int i = 0; i < m; i++) cin >> s[i];
        sort(s.begin(), s.end());
        int q, p;
        if (a < b) q = b-a-1, p = a-1;
        else q = a-b-1, p = n-a;
        int tempo = q+p+1;
        int at = 1;
        int res = 0;
        for (int i = m-1; i >= 0; i--) {
			if (at > q) break;
			if (at + s[i] <= tempo) res++, at++;
		}
		cout << res << "\n";
    }
}