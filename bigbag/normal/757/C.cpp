#include <ctime>
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

const int max_n = 1011111, MOD = 1000000007;

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int x) {
    for (int i = x + 1; ; ++i) {
        if (is_prime(i)) {
            return i;
        }
    }
}

const int N = 101111;

long long h[N], pw[N];
int h2[N], pw2[N], mod;

void proc() {
    srand(time(NULL));
    int p = next_prime(100 + rand() % 200);
    int p2 = next_prime(100 + rand() % 200);
    mod = next_prime(1000000000 + rand() % 1000);
    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = pw[i - 1] * p;
    }
    pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw2[i] = (1LL * pw2[i - 1] * p2) % mod;
    }
}

int n, m, f[max_n];
pair<long long, int> p[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int cnt;
        scanf("%d", &cnt);
        while (cnt--) {
            int col;
            scanf("%d", &col);
            --col;
            all[col].push_back(i);
        }
    }
    sort(all, all + m);
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % MOD;
    }
    int ans = 1;
    for (int i = 0; i < m; ++i) {
        //cout << "#" << i << endl;
        int cnt = 1;
        while (i + 1 < m && all[i] == all[i + 1]) {
            ++cnt;
            ++i;
        }
        ans = (1LL * ans * f[cnt]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}