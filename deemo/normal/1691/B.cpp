#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n, a[MAXN], p[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        cin >> n;
        map<int, vector<int>> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (!cnt.count(a[i]))
                cnt[a[i]] = vector<int> {i};
            else
                cnt[a[i]].push_back(i);
        }
        for (auto &[c, v]: cnt)
            if (v.size() < 2) {
                cout << "-1\n";
                goto there;
            } else {
                deque<int> cp(v.begin(), v.end());
                cp.push_back(cp.front());
                cp.pop_front();
                for (auto x: v) {
                    p[x] = cp.front();
                    cp.pop_front();
                }
            }

        for (int i = 0; i < n; i++)
            cout << p[i]+1 << " ";
        cout << "\n";

there:;
    }
    return 0;
}