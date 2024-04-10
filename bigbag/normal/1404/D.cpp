#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000555, inf = 1000111222;

int n, a[max_n], sz[max_n], ans[max_n], used[max_n];
vector<int> all[max_n];
long long sum;

void dfs(int pos) {
    sum += a[pos];
    ans[a[pos]] = 1;
    used[a[pos] % n] = 1;
    int x = a[pos ^ 1] % n;
    if (!used[x]) {
        int to = all[x][0] ^ all[x][1] ^ pos ^ 1;
        dfs(to);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n % 2) {
        cout << "Second" << endl;
        for (int i = 0; i < 2 * n; ++i) {
            int num;
            cin >> num;
            --num;
            a[2 * num + sz[num]++] = i + 1;
        }
        for (int i = 0; i < 2 * n; ++i) {
            all[a[i] % n].push_back(i);
        }
        for (int i = 0; i < 2 * n; ++i) {
            if (!used[a[i] % n]) {
                dfs(i);
            }
        }
        if (sum % (2 * n)) {
            for (int i = 1; i <= 2 * n; ++i) {
                ans[i] ^= 1;
            }
        }
        for (int i = 1; i <= 2 * n; ++i) {
            if (ans[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        return 0;
    } else {
        cout << "First" << endl;
        for (int i = 0; i + 1 < n; ++i) {
            a[i] = i;
        }
        a[n - 1] = 2 * n - 2;
        a[n] = n - 1;
        a[n + 1] = 2 * n - 1;
        for (int i = n + 2; i < 2 * n; ++i) {
            a[i] = i - 2;
        }
        for (int i = 0; i < 2 * n; ++i) {
            ans[a[i]] = i / 2;
        }
        for (int i = 0; i < 2 * n; ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}