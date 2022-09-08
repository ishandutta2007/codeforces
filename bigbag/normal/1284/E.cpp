#include <bits/stdc++.h>

using namespace std;

const int max_n = 2555, inf = 1000111222;

struct point {
    int x, y;

    point() {
    }

    point(int x, int y): x(x), y(y) {
    }

    point operator - (const point &p) const {
        return {x - p.x, y - p.y};
    }
};

long long vect_pr(const point &a, const point &b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

point O;

int get_z(int x) {
    if (x == 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    }
    return -1;
}

bool cmp(const point &a, const point &b) {
    if (get_z(a.y) * get_z(b.y) < 0) {
        return get_z(a.y) >= 0;
    }
    if (get_z(a.y) * get_z(b.y) == 0) {
        if (std::min(get_z(a.y), get_z(b.y)) == -1) {
            return get_z(a.y) == 0;
        }
    }
    return vect_pr(a, b) > 0;
}

int n, add[max_n], sum[max_n];
point p[max_n];
vector<point> v;

long long c2(long long cnt) {
    if (cnt < 2) {
        return 0;
    }
    return (cnt * (cnt - 1)) / 2;
}

long long c3(long long n) {
    if (n < 3) {
        return 0;
    }
    return n * (n - 1) * (n - 2) / 6;
}

long long c4(long long n) {
    return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

long long solve() {
    sort(v.begin(), v.end(), cmp);
    long long res = 0;
    /*for (int i = 0; i < v.size(); ++i) {
        cout << v[i].x << " " << v[i].y << endl;
    }
    cout << endl;*/
    /*if (vect_pr(v[0], v.back()) >= 0) {
        return c4(v.size());
    }*/
    int pos = 0;
    int csz = v.size();
    for (int i = 0; i < csz; ++i) {
        v.push_back(v[i]);
    }
    for (int i = 0; i < csz; ++i) {
        while (pos < i + csz && vect_pr(v[i], v[pos]) >= 0) {
            ++pos;
        }
        //cout << pos - i - 1 << endl;
        res += c3(pos - i - 1);
    }
    //cout << "res = " << res << "   " << c4(n - 1) << endl;
    /*memset(add, 0, sizeof(add));
    int pos = 0;
    while (pos < v.size() && vect_pr(v[0], v[pos]) >= 0) {
        ++pos;
    }
    int st = 0;
    for (int i = pos; i < v.size(); ++i) {
        while (vect_pr(v[i], v[st]) > 0) {
            ++st;
            ++add[i];
        }
    }
    sum[0] = add[0];
    //cout << "pos = " << pos << ": ";
    for (int i = 1; i < v.size(); ++i) {
        sum[i] = sum[i - 1] + add[i];
        //cout << sum[i] << " ";
    }
    //cout << endl;
    pos = 0;
    for (int i = 0; i < v.size(); ++i) {
        while (pos < v.size() && vect_pr(v[i], v[pos]) >= 0) {
            ++pos;
        }
        if (pos == v.size()) {
            break;
        }
        int st = sum[pos] - i - 1;
        for (int j = pos; j < v.size(); ++j) {
            cout << "$" << st << endl;
            res += st * st - st;
            if (j + 1 < v.size()) {
                st += 1 + add[j + 1];
            }
        }
    }
    assert(res % 2 == 0);
    res /= 2;
    cout << res << endl;*/
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    long long ans = 1LL * n * c4(n - 1);
    for (int i = 0; i < n; ++i) {
        v.clear();
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                v.push_back(p[j] - p[i]);
            }
        }
        ans -= solve();
    }
    cout << ans << "\n";
    return 0;
}