#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200222, inf = 1000111222;

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

int n, m, a[max_n], x[max_n], d[max_n], dx[max_n], z1[2 * max_n], z2[2 * max_n];

void get_z_function(const vector<int> &v, int z[]) {
    int l = 0, r = 0;
    z[0] = 0;
    for (int i = 0; i < v.size() + 5; ++i) {
        z[i] = 0;
    }
    for (int i = 1; i < v.size(); ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < v.size() && v[i + z[i]] == v[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

set<int> triv() {
    set<int> ans;
    for (int i = 0; i < n; ++i) {
        int x = (a[0] + a[i]) % m;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (x != (a[j] + a[(i + n - j) % n]) % m) {
                //cout << x << " " << j << endl;
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.insert(x);
        }
    }
    return ans;
}

set<int> solve() {
    for (int i = 0; i < n; ++i) {
        x[i] = a[i] + a[0];
        d[i] = a[i] - a[i - 1];
    }
    for (int i = 0; i + 1 < n; ++i) {
        dx[i] = x[i + 1] - x[i];
    }
    vector<int> v;
    for (int i = 0; i + 1 < n; ++i) {
        v.push_back(dx[i]);
    }
    v.push_back(inf);
    for (int i = n - 1; i >= 0; --i) {
        v.push_back(d[i]);
    }
    get_z_function(v, z1);

    v.clear();
    for (int i = n - 2; i >= 0; --i) {
        v.push_back(dx[i]);
    }
    v.push_back(inf);
    for (int i = 1; i < n; ++i) {
        v.push_back(d[i]);
    }
    get_z_function(v, z2);

    set<int> ans;
    for (int i = 0; i < n; ++i) {
        //cout << x[i] << " " << z1[2 * n - 1 - i] << " " << z2[n + i] << ", " << x[n - 1] << " " << x[i + 1] - x[0] << " " << x[i] + m << endl;
        if (z1[2 * n - 1 - i] >= i && z2[n + i + 1] >= n - i - 2 && (i + 1 == n || x[n - 1] + x[i + 1] - x[0] == x[i] + m)) {
            ans.insert(x[i] % m);
        }
    }
    return ans;
}

const bool debug = 0;

int main() {
    //freopen("inputB.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        while (true) {
            n = rnd(1, 5);
            m = rnd(n + 1, 2 * n + 2);
            set<int> q;
            while (q.size() < n) {
                q.insert(rnd(m));
            }
            for (int i = 0; i < n; ++i) {
                a[i] = *q.begin();
                q.erase(a[i]);
            }
            set<int> ok = triv();
            set<int> wa = solve();
            if (wa != ok) {
                cout << "WA" << endl;
                cout << n << " " << m << endl;
                for (int i = 0; i < n; ++i) {
                    cout << a[i] << " ";
                }
                cout << endl;
                cout << "OK: ";
                for (int x : ok) {
                    cout << x << " ";
                }
                cout << endl;
                cout << "WA: ";
                for (int x : wa) {
                    cout << x << " ";
                }
                cout << endl;
                exit(0);
            }
            cout << "+";
        }
    } else {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
    }
    /*if (m > 2000) {
        puts("0");
        return 0;
    }*/
    set<int> ans = solve();
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    return 0;
}