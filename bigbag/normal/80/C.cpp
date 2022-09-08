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

const int max_n = 11, inf = 1111111111;

map<string, int> m;
int n, a, b, c, num[max_n], f[max_n][max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    m["Anka"] = 1;
    m["Chapay"] = 2;
    m["Cleo"] = 3;
    m["Troll"] = 4;
    m["Dracul"] = 5;
    m["Snowy"] = 6;
    m["Hexadecimal"] = 7;
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b >> b;
        f[m[a]][m[b]] = 1;
    }
    cin >> a >> b >> c;
    for (int i = 1; i <= 7; ++i) {
        num[i] = i;
    }
    int rr = inf, max_simp = 0;
    do {
        for (int i = 1; i <= 9; ++i) {
            for (int j = i + 2; j <= 8; ++j) {
                vector<int> v1, v2, v3;
                int cnt = 1;
                for (int k = 1; k < i; ++k) {
                    v1.push_back(num[k]);
                }
                for (int k = i + 1; k < j; ++k) {
                    v2.push_back(num[k - 1]);
                }
                for (int k = j + 1; k <= 9; ++k) {
                    v3.push_back(num[k - 2]);
                }
                if (v1.size() != 0 && v2.size() != 0 && v3.size() != 0) {
                    int simp = 0;
                    for (int k = 0; k < v1.size(); ++k) {
                        for (int q = 0; q < v1.size(); ++q) {
                            if (k != q) simp += f[v1[k]][v1[q]];
                        }
                    }
                    for (int k = 0; k < v2.size(); ++k) {
                        for (int q = 0; q < v2.size(); ++q) {
                            if (k != q) simp += f[v2[k]][v2[q]];
                        }
                    }
                    for (int k = 0; k < v3.size(); ++k) {
                        for (int q = 0; q < v3.size(); ++q) {
                            if (k != q) simp += f[v3[k]][v3[q]];
                        }
                    }
                    int o1 = a / v1.size();
                    int o2 = b / v2.size();
                    int o3 = c / v3.size();
                    int fr = max(o1, max(o2, o3)) - min(o1, min(o2, o3));
                    if (fr < rr || fr == rr && simp > max_simp) {
                        rr = fr;
                        max_simp = simp;
                    }
                }
            }
        }
        //cout << max_simp << endl;
    } while (next_permutation(num + 1, num + 8));
    cout << rr << ' ' << max_simp << endl;
    return 0;
}