#include <bits/stdc++.h>
using namespace std;

char t[2555];
int f[55];

int main() {
    string s;
    int n, k; cin >> n >> k >> s;
    f[1] = 0;
    for (int j = 0, i = 1; i < n; i++) {
        while (j && s[j] != s[i]) j = f[j];
        if (s[i] == s[j]) j++;
        f[i + 1] = j;
    }
    for (int i = 0; i < n; i++) t[i] = s[i];
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < n - f[n]; j++) {
            t[n + i * (n - f[n]) + j] = s[f[n] + j];
        }
    }
    cout << t << endl;
}