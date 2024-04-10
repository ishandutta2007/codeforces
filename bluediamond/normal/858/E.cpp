#include <bits/stdc++.h>

using namespace std;

string get(int n) {
        if (n == 0) {
                return "0";
        }
        string sol;
        while (n) {
                sol += (char) ('0' + n % 10);
                n /= 10;
        }
        reverse(sol.begin(), sol.end());
        return sol;
}

int nr(string s) {
        if (s.empty()) {
                cout << "why empty???\n";
                exit(0);
        }
        if (s[0] == '0') {
                return -1;
        }
        int sol = 0;
        for (auto &c : s) {
                if (c < '0' || '9' < c) {
                        return -1;
                }
                sol = 10 * sol + c - '0';
        }
        return sol;
}

const int N = (int) 1e5 + 7;
int n;
string a[N];
int t[N];
int e;
set<string> s;
vector<pair<string, string>> sol;
set<int> ints;

int urm(int x) {
        return *ints.lower_bound(x);
}

void make(int i, string kek) {
        int x = nr(a[i]);
        if (1 <= x) {
                ints.insert(x);
        }
        s.erase(a[i]);
        s.insert(kek);
        sol.push_back({a[i], kek});
        a[i] = kek;
        x = nr(kek);
        if (1 <= x) {
                ints.erase(x);
        }
}

bool bring(int t, int i) {
        int val;
        if (t == 0) {
                val = urm(e + 1);
                if (val > n) {
                        return 0;
                }
        } else {
                val = urm(1);
                if (val > e) {
                        return 0;
                }
        }
        make(i, get(val));
        return 1;
}

void solve() {
        int unknown = 0;
        for (int i = 1; i <= n; i++) {
                int x = nr(a[i]);
                if (x < 1 || x > n) {
                        unknown++;
                }
        }
        if (unknown == 0) {
                bool correct = 1;
                for (int i = 1; i <= n; i++) {
                        int l, r;
                        if (t[i] == 1) {
                                l = 1;
                                r = e;
                        } else {
                                l = e + 1;
                                r = n;
                        }
                        int x = nr(a[i]);
                        if (x < l || r < x) {
                                correct = 0;
                                make(i, get(n + 1));
                                break;
                        }
                }
                if (correct) {
                        return;
                }

        }
        vector<vector<int>> need(2);
        for (int i = 1; i <= n; i++) {
                int x = nr(a[i]);
                if (1 <= x && x <= e) {
                        if (t[i] == 0) {
                                need[0].push_back(i);
                        }
                }
                if (e + 1 <= x && x <= n) {
                        if (t[i] == 1) {
                                need[1].push_back(i);
                        }
                }
        }
        int sz0 = (int) need[0].size(), sz1 = (int) need[1].size();
        int to = min(sz0, sz1);
        for (int i = 0; i < to; i++) {
                if (bring(0, need[0][i])) {
                        bring(1, need[1][i]);
                } else {
                        bring(1, need[1][i]);
                        bring(0, need[0][i]);
                }
        }
        for (int i = to; i < sz0; i++) bring(0, need[0][i]);
        for (int i = to; i < sz1; i++) bring(1, need[1][i]);
        for (int i = 1; i <= n; i++) {
                int x = nr(a[i]);
                if (x < 1 || x > n) {
                        if (t[i] == 1) {
                                make(i, get(urm(1)));
                        } else {
                                make(i, get(urm(e + 1)));
                        }
                }
        }
}

void print() {
        cout << (int) sol.size() << "\n";
        for (auto &x : sol) {
                cout << "move " << x.first << " " << x.second << "\n";
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
                ints.insert(i);
        }
        for (int i = 1; i <= n; i++) {
                cin >> a[i] >> t[i];
                int x = nr(a[i]);
                if (1 <= x) {
                        ints.erase(x);
                }
                e += t[i];
                s.insert(a[i]);
        }
        solve();
        print();
}