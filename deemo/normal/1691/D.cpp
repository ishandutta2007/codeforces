#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n, a[MAXN];
ll p[MAXN];
int best[MAXN];

int sec[MAXN];
bool check(bool rev = false) {
    if (rev) {
        reverse(a, a + n);
    }
    for (int i = 0; i < n; i++)
        p[i+1] = p[i] + a[i];
    int sz = 0;
    for (int i = 0; i < n; i++) {
        best[i] = i;
        while (sz && a[i] >= a[sec[sz-1]]) {
            sz--;
            if (p[i+1] - p[best[i]] < p[i+1] - p[best[sec[sz]]])
                best[i] = best[sec[sz]];
        }
        if (p[i+1] - p[best[i]] > a[i])
            return true;
        sec[sz++] = i;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (check() || check(1))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}