#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

vector<int> ans[N];
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        b[i] = (b[i - 1] + a[i]) % n;
    }
    b[m] = n;
    sort(b, b + m);
    for (int i = m; i > 0; i--) b[i] -= b[i - 1];
    int cur = 1;
    for (int i = 1; i <= m; i++) {
        while (a[i] > 0) {
            a[i] -= b[cur];
            ans[cur].push_back(i);
            cur = cur % m + 1;
        }
    }
    int cnt = ans[1].size();
    cout << cnt << '\n';
    for (int i = 1; i <= m; i++) cout << b[i] << ' ';
    cout << '\n';
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j <= m; j++) {
            int ret = (ans[j].size() <= i ? ans[1][i] : ans[j][i]);
            cout << ret << ' ';
        }
        cout << '\n';
    }
    return 0;
}