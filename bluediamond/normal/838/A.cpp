#include <bits/stdc++.h>>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5000 + 7;

int n, m;
int v[N][N];
int s[N][N];

int get(int r1, int c1, int r2, int c2) {
        return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
}

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
                string s;
                cin >> s;
                for(int j = 1; j <= m; j++) {
                        v[i][j] = (s[j - 1] - '0');
                }
        }
        for(int i = 0; i < N; i++) {
                int cur = 0;
                for(int j = 0; j < N; j++) {
                        cur += v[i][j];
                        s[i][j] = cur;
                        if(i > 0) {
                                s[i][j] += s[i - 1][j];
                        }
                }
        }
        int res = (1 << 30);
        for(int k = 2; k <= max(n, m); k++) {
                int szn;
                int szm;
                if(n % k == 0) {
                        szn = n;
                } else {
                        szn = (n / k + 1) * k;
                }
                if(m % k == 0) {
                        szm = m;
                } else {
                        szm = (m / k + 1) * k;
                }
                int cur = 0;
                for(int i = 1; i <= szn; i += k) {
                        for(int j = 1; j <= szm; j += k) {
                                int cnt1 = get(i, j, i + k - 1, j + k - 1);
                                cur += min(cnt1, k * k - cnt1);
                        }
                }
                res = min(res, cur);
        }
        cout << res << "\n";
        return 0;
}