/**
 *  created: 16/04/2021, 17:37:47
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;

}

int t, n;
string a[3];

void solve() {
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            for (char c = '0'; c <= '1'; ++c) {
                vector<int> v[2];
                for (int k = 0; k < 2 * n; ++k) {
                    if (a[i][k] == c) {
                        v[0].push_back(k);
                    }
                    if (a[j][k] == c) {
                        v[1].push_back(k);
                    }
                }
                if (v[0].size() >= n && v[1].size() >= n) {
                    string ans;
                    int pos1 = 0, pos2 = 0;
                    for (int k = 0; k < n; ++k) {
                        while (pos1 < v[0][k]) {
                            ans += a[i][pos1++];
                        }
                        ++pos1;
                        while (pos2 < v[1][k]) {
                            ans += a[j][pos2++];
                        }
                        ++pos2;
                        ans += c;
                    }
                    while (pos1 < 2 * n) {
                        ans += a[i][pos1++];
                    }
                    while (pos2 < 2 * n) {
                        ans += a[j][pos2++];
                    }
                    assert(ans.size() <= 3 * n);
                    //cout << i << " " << j << " " << c << ": ";
                    puts(ans.c_str());
                    return;
                }
            }
        }
    }
    cout << "#" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << a[i] << endl;
    }
    exit(2);
}

mt19937 gen;

int rnd() {
    return gen() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        if (0) {
            n = rnd(1, 5);
            for (int i = 0; i < 3; ++i) {
                a[i] = "";
                for (int j = 0; j < 2 * n; ++j) {
                    a[i] += '0' + rnd(2);
                }
            }
        } else {
            scanf("%d", &n);
            a[0] = read();
            a[1] = read();
            a[2] = read();
        }
        solve();
    }
    return 0;
}