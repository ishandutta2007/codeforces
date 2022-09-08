#include <bits/stdc++.h>

using namespace std;

const int max_n = 100000;

int mod;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2);
    }
    return (1LL * a * power(a, b - 1)) % mod;
}

int u, v;
vector<int> paths[max_n];
map<int, int> q;

vector<int> gen_path(int x) {
    vector<int> res(101);
    for (int i = 0; i < 100; ++i) {
        int tp = rand() % 3;
        res[i] = tp;
        if (tp == 0) {
            x += 1;
            x %= mod;
        } else if (tp == 1) {
            x += mod - 1;
            x %= mod;
        } else {
            x = power(x, mod - 2);
        }
    }
    res[100] = x;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    srand(time(NULL));
    cin >> u >> v >> mod;
    for (int i = 0; i < max_n; ++i) {
        paths[i] = gen_path(u);
        q[paths[i].back()] = i;
        paths[i].pop_back();
    }
    while (true) {
        vector<int> path = gen_path(v);
        int x = path.back();
        path.pop_back();
        if (q.count(x)) {
            int id = q[x];
            vector<int> ans = paths[id];
            reverse(path.begin(), path.end());
            for (int tp : path) {
                if (tp <= 1) {
                    ans.push_back(tp ^ 1);
                } else {
                    ans.push_back(tp);
                }
            }
            cout << ans.size() << endl;
            for (int tp : ans) {
                cout << tp + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}