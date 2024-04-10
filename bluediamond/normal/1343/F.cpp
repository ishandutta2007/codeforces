#include <bits/stdc++.h>

using namespace std;

const int N = 200 + 7;
set<int> s[N];
set<int> s2[N];
int n;
int sol[N];
int pos[N];

void del(int x) {
        for (int i = 1; i < n; i++) {
                s[i].erase(x);
        }
}

bool can_be_first(int x) {
        sol[1] = x;
        del(x);
        for (int i = 2; i <= n; i++) {
                sol[i] = 0;
                for (int j = 1; j < n; j++) {
                        if ((int) s[j].size() == 1) {
                                if (sol[i]) {
                                        return 0;
                                }
                                pos[j] = i;
                                int x = *s[j].begin();
                                sol[i] = x;
                                del(x);
                                break;
                        }
                }
                if (!sol[i]) {
                        return 0;
                }
        }
        for (int i = 1; i < n; i++) {
                int l = (int) s2[i].size();
                set<int> expected;
                for (int j = pos[i] - l + 1; j <= pos[i]; j++) {
                        expected.insert(sol[j]);
                }
                if (expected != s2[i]) {
                        return 0;
                }
        }
        for (int i = 1; i <= n; i++) {
                cout << sol[i] << " ";
        }
        cout << "\n";
        return 1;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 1; i < n; i++) {
                        s[i].clear();
                        int len;
                        cin >> len;
                        for (int j = 1; j <= len; j++) {
                                int x;
                                cin >> x;
                                s[i].insert(x);
                        }
                        s2[i] = s[i];
                }
                for (int x = 1; x <= n; x++) {
                        if (can_be_first(x)) {
                                break;
                        }
                        for (int i = 1; i < n; i++) {
                                s[i] = s2[i];
                        }
                }
        }
}