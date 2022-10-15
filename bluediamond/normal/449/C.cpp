#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
vector<int> p;
vector<int> v[N];
int lp[N];
vector<pair<int, int>> sol;
bool taken[N];

void add(int i, int j) {
        sol.push_back({i, j});
}

void print() {
        cout << (int) sol.size() << "\n";
        for (auto &it : sol) {
                cout << it.first << " " << it.second << "\n";
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
                if (lp[i] == 0) {
                        p.push_back(i);
                        lp[i] = i;
                }
                for (int j = 0; j < (int) p.size() && p[j] <= lp[i] && p[j] * i <= n; j++) {
                        lp[p[j] * i] = p[j];
                }
                v[lp[i]].push_back(i);
        }
        reverse(p.begin(), p.end());
        for (auto &x : p) {
                if (2 * x > n) {
                        continue;
                }
                if (x == 2) {
                        vector<int> r;
                        for (int j = 2; j <= n; j += 2) {
                                if (taken[j] == 0) {
                                        r.push_back(j);
                                }
                        }
                        for (int j = 1; j < (int) r.size(); j += 2) {
                                add(r[j - 1], r[j]);
                        }
                        continue;
                }
                if ((int) v[x].size() % 2 == 1) {
                        taken[2 * x] = 1;
                        v[x].push_back(2 * x);
                }
                for (int j = 1; j < (int) v[x].size(); j += 2) {
                        add(v[x][j - 1], v[x][j]);
                }
        }
        print();
}