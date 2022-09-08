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

const int max_n = 111111, inf = 1111111111;

int p, q;

const int max_p = 2011111;

int used[max_p], r[max_n], cnt[max_p], pw[11];
vector<int> v;

void get_all_primes() {
    used[1] = 1;
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            if ((long long) i * i < (long long) max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int rev(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

void rec(int poz, int x) {
    if (x * pw[poz] + r[x] < max_p) {
        v.push_back(x * pw[poz] + r[x]);
    }
    if (x * pw[poz - 1] + r[x / 10] < max_p) {
        v.push_back(x * pw[poz - 1] + r[x / 10]);
    }
    if (poz == 4) {
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        rec(poz + 1, x * 10 + i);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    int a = 11109;
    for (int i = 1; i < max_p; ++i) {
        used[i] = 1 - used[i] + used[i - 1];
    }
    for (int i = 0; i < max_n; ++i) {
        r[i] = rev(i);
    }
    pw[0] = 1;
    for (int i = 1; i < 9; ++i) {
        pw[i] = pw[i - 1] * 10;
    }
    for (int i = 1; i <= 9; ++i) {
        rec(1, i);
    }
    for (int i = 0; i < v.size(); ++i) {
        cnt[v[i]] = 1;
    }
    for (int i = 1; i < max_p; ++i) {
        cnt[i] += cnt[i - 1];
    }
    cin >> p >> q;
    for (int i = max_p - 1; i >= 0; --i) {
        if (used[i] * q <= p * cnt[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}