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

const int max_p = 450, max_n = 100000, inf = 1000000007;

int used[max_p];
vector<int> p;

void get_all_prime() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            p.push_back(i);
            for (int j = 2; i * j < max_p; ++j) {
                used[i * j] = 1;
            }
        }
    }
}

struct very_long1 {
    int cnt[2 * max_n];
    very_long1() {
        memset(cnt, 0, sizeof(cnt));
    }
    void operator = (int x) {
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            int q = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                ++cnt[p[i]];
            }
        }
        if (x != 1) {
            ++cnt[x];
        }
    }
    void operator *= (int x) {
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            int q = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                ++cnt[p[i]];
            }
        }
        if (x != 1) {
            ++cnt[x];
        }
    }
    void operator /= (int x) {
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            int q = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                --cnt[p[i]];
            }
        }
        if (x != 1) {
            --cnt[x];
        }
    }
};

long long step(long long a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    if (b % 2 == 0) {
        return step(a * a, b / 2);
    }
    return a * step(a, b - 1);
}

long long very_long1_to_very_long(very_long1 x) {
    long long res = 1;
    for (int i = 2; i < 2 * max_n; ++i) {
        if (x.cnt[i] != 0) {
            //cout << "(" << i << "; " << x.cnt[i] << ") ";
            res = (res * step(i, x.cnt[i])) % inf;
        }
    }
    return res;
}

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_prime();
    cin >> n;
    int x = n - 1, y = 0;
    very_long1 C;
    C = 1;
    for (int i = 2; i <= 2 * n - 1; ++i) {
        C *= i;
    }
    for (int i = 2; i <= n; ++i) {
        C /= i;
    }
    for (int i = 2; i <= n - 1; ++i) {
        C /= i;
    }
    long long ans = very_long1_to_very_long(C);
    //print(ans);
    //cout << endl;
    cout << (ans + ans - n) % inf << endl;
    //print(ans + ans - n);
    return 0;
}