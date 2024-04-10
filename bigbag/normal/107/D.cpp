#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 131, mod = 12345;

long long n;
int m, C, cnt[max_n], l[max_n], r[max_n], num[max_n];
vector<int> v[max_n], v1;
map<vector<int>, int> q1;
map<int, vector<int> > q2;

void rec(int poz) {
    if (num[poz] == 0) {
        q1[v1] = C;
        q2[C] = v1;
        ++C;
        return;
    }
    int c = num[poz];
    for (int i = 0; i < v[c][poz - l[c]]; ++i) {
        v1[poz] = i;
        rec(poz + 1);
    }
}

struct matrix {
    vector<vector<int> > v;
    matrix() {
    }
    matrix(int n, int m) {
        v.resize(n, vector<int>(m, 0));
    }
    matrix operator * (const matrix &m) const {
        matrix res(v.size(), m.v[0].size());
        for (int i = 0; i < res.v.size(); ++i) {
            for (int j = 0; j < res.v[i].size(); ++j) {
                for (int k = 0; k < v[i].size(); ++k) {
                    res.v[i][j] += 1LL * v[i][k] * m.v[k][j];
                    res.v[i][j] %= mod;
                }
            }
        }
        return res;
    }
    void write(const string &s = "") const {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};

matrix power(matrix a, long long b) {
    matrix res(a.v.size(), a.v.size());
    for (int i = 0; i < res.v.size(); ++i) {
        res.v[i][i] = 1;
    }
    while (b) {
        if (b % 2 == 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

matrix A, B;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (m--) {
        char c;
        int x;
        cin >> c >> x;
        v[c].push_back(x);
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        sort(v[c].begin(), v[c].end());
        v[c].erase(unique(v[c].begin(), v[c].end()), v[c].end());
        cnt[c] = cnt[c - 1] + v[c].size();
        l[c] = cnt[c - 1];
        r[c] = cnt[c] - 1;
        for (int i = l[c]; i <= r[c]; ++i) {
            num[i] = c;
            v1.push_back(0);
        }
    }
    rec(0);
    A = matrix(1, C);
    B = matrix(C, C);
    A.v[0][0] = 1;
    for (int i = 0; i < C; ++i) {
        v1 = q2[i];
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (v[c].size()) {
                for (int j = l[c]; j <= r[c]; ++j) {
                    ++v1[j];
                    v1[j] %= v[c][j - l[c]];
                }
                int num = q1[v1];
                ++B.v[i][num];
                for (int j = l[c]; j <= r[c]; ++j) {
                    --v1[j];
                    v1[j] += v[c][j - l[c]];
                    v1[j] %= v[c][j - l[c]];
                }
            }
        }
    }
    B = power(B, n);
    A = A * B;
    int ans = 0;
    for (int i = 0; i < C; ++i) {
        v1 = q2[i];
        int f = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            int ff = 0;
            for (int j = l[c]; j <= r[c]; ++j) {
                if (v1[j] == 0) {
                    ff = 1;
                    break;
                }
            }
            if (l[c] <= r[c] && ff == 0) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            ans = (ans + A.v[0][i]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}