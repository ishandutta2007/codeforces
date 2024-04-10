#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int to[N];
bool ok[N];
bool vis[N];

int ending(int a) {
        if (vis[a]) {
                return a;
        } else {
                vis[a] = 1;
                return ending(to[a]);
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                ok[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
                cin >> to[i];
                ok[to[i]] = 0;
        }
        vector<pair<int, int>> kek;
        int ca = 0;
        for (int i = 1; i <= n; i++) {
                if (ok[i]) {
                        ca++;
                        kek.push_back({i, ending(i)});
                }
        }
        int cb = 0;
        for (int i = 1; i <= n; i++) {
                if (vis[i] == 0) {
                        cb++;
                        kek.push_back({i, ending(i)});
                }
        }
        if (ca == 0 && cb == 1) {
                cout << "0\n";
                return 0;
        }
        cout << (int) kek.size() << "\n";
        for (int i = 0; i < (int) kek.size(); i++) {
                int j = i + 1;
                if (i == (int) kek.size() - 1) {
                        j = 0;
                }
                cout << kek[i].second << " " << kek[j].first << "\n";
        }
}