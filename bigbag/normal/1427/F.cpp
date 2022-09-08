#include <bits/stdc++.h>

using namespace std;

const int max_n = 1333, inf = 1000111222;

int n, f[max_n];

vector<int> getok(vector<int> v) {
    vector<int> res, cur;
    res.push_back(1);
    for (int x : v) {
        cur.push_back(f[x]);
        if (cur.size() >= 3 && (cur[cur.size() - 1] + cur[cur.size() - 2] + cur[cur.size() - 3]) % 3 == 0) {
            cur.pop_back();
            cur.pop_back();
            cur.pop_back();
        }
        res.push_back(cur.empty());
    }
    return res;
}

void solve() {
    vector<int> v;
    for (int i = 1; i <= 6 * n; ++i) {
        v.push_back(i);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        bool ok = 0;
        vector<int> rv(v.rbegin(), v.rend());
        vector<int> ok1 = getok(v);
        vector<int> ok2 = getok(rv);
        for (int it = 0; it < 2; ++it) {
            for (int j = 0; j + 2 < v.size() && !ok; ++j) {
                if (f[v[j]] == f[v[j + 1]] && f[v[j + 1]] == f[v[j + 2]] && f[v[j]] == i % 2) {
                    if (it == 1 || i % 2 == 1 || !ok1[j] || !ok2[v.size() - j - 3]) {
                        cout << v[j] << " " << v[j + 1] << " " << v[j + 2] << "\n";
                        v.erase(v.begin() + j, v.begin() + j + 3);
                        ok = 1;
                        break;
                    }
                }
            }
        }
        if (!ok) {
            exit(i);
        }
    }
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        for (int test = 0; test < 111111; ++test) {
            n = rnd(1, 10);
            fill(f, f + 6 * n + 1, 0);
            vector<int> v;
            for (int i = 1; i <= 6 * n; ++i) {
                v.push_back(i);
            }
            for (int i = 1; i <= 2 * n; ++i) {
                int pos = rnd(v.size() - 2);
                f[v[pos]] = f[v[pos + 1]] = f[v[pos + 2]] = i % 2;
                v.erase(v.begin() + pos, v.begin() + pos + 3);
            }
            if (0 || test % 1000 == 0) {
                cout << n << endl;
                for (int i = 1; i <= 6 * n; ++i) {
                    if (f[i]) {
                        cout << i << " ";
                    }
                }
                cout << endl;
            }
            solve();
        }
        return 0;
    }
    cin >> n;
    for (int i = 0; i < 3 * n; ++i) {
        int x;
        cin >> x;
        f[x] = 1;
    }
    solve();
    return 0;
}