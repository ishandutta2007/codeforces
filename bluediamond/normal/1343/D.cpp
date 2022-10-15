#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
int k;
int a[N], b[N];
int cnt[2 * N];

multiset<int> ids;
set<int> uniq;
vector<int> intr[2 * N];

void ins(int x) {
        ids.insert(x);
        uniq.insert(x);
}

void del(int x) {
        ids.erase(ids.find(x));
        if (ids.count(x) == 0) {
                uniq.erase(x);
        }
}

int get() {
        return (int) uniq.size();
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                cin >> n >> k;
                for (int i = 1; i <= n / 2; i++) {
                        cin >> a[i];
                }
                for (int i = n / 2; i >= 1; i--) {
                        cin >> b[i];
                }
                n /= 2;
                ids.clear();
                uniq.clear();
                for (int i = 1; i <= 2 * k; i++) {
                        cnt[i] = 0;
                        intr[i].clear();
                }
                for (int i = 1; i <= n; i++) {
                        intr[a[i]].push_back(i);
                        intr[b[i]].push_back(i);
                }
                for (int i = 1; i <= n; i++) {
                        cnt[a[i] + b[i]]++;
                }
                int sol = (int) 1e9;
                for (int x = 1; x <= 2 * k; x++) {
                        if (x - k - 1 >= 0) {
                                for (auto &it : intr[x - k - 1]) {
                                        del(it);
                                }
                        }
                        if (x - 1 >= 0) {
                                for (auto &it : intr[x - 1]) {
                                        ins(it);
                                }
                        }
                        int lol = get() - cnt[x];
                        int cur = lol + 2 * (n - lol - cnt[x]);
                        sol = min(sol, cur);
                }
                cout << sol << "\n";
        }
}