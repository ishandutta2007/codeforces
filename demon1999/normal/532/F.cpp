#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxn = 5 * 100000;

bool f(int a, int b, int k) {
    if (a == b) return true;
    if (b == -1 && a >= k) return true;
    return false;
}

vector<int> ans;
int cur[30];
int a[maxn], p[maxn], u[30];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 26; ++i) cur[i] = -1;
    for (int i = 0; i < m; ++i) {
        if (cur[t[i] - 'a'] != -1) a[i] = i - cur[t[i] - 'a'];
        else a[i] = -1;
        cur[t[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; ++i) cur[i] = -1;
    a[m] = -2;
    for (int i = 0; i < n; ++i) {
        if (cur[s[i] - 'a'] != -1) a[m + i + 1] = i - cur[s[i] - 'a'];
        else a[m + i + 1] = -1;
        cur[s[i] - 'a'] = i;
    }
    p[0] = 0;
    for (int i = 1; i <= n + m; ++i) {
        int j = p[i - 1];
        while (j > 0 && !f(a[i], a[j], j)) j = p[j - 1];
        if (f(a[i], a[j], j)) j++;
        p[i] = j;
    }
    for (int i = 0; i < 26; ++i) cur[i] = -1;
    for (int i = 0; i < m; ++i) {
        cur[t[i] - 'a'] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (p[i + m + m] == m) {
            bool fl = true;
            for (int j = 0; j < 26; ++j) u[j] = -1;
            for (int j = 0; j < 26; ++j) {
                if (cur[j] == -1) continue;
                int k = s[i + cur[j]] - 'a';
                if (u[k] != -1 && u[k] != j) fl = false;
                if (u[j] != -1 && u[j] != k) fl = false;
                u[k] = j;
                u[j] = k;
            }
            if (fl) ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << ' ';

    return 0;
}