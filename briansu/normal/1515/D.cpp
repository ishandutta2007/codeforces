#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> s(n + 1);
        for (int i = 1, a; i <= l; i++)
            cin >> a, s[a]++;
        for (int i = 1, a; i <= r; i++)
            cin >> a, s[a]--;
        if (l < r)
            for (int i = 1; i <= n; i++)
                s[i] = -s[i];
        int tt = 0, can_flip = 0;
        for (int i = 1; i <= n; i++) {
            tt += abs(s[i]);
            if (s[i] > 0)
                can_flip += s[i] / 2;
        }
        if (can_flip >= abs(r - l) / 2)
            cout << tt / 2 << "\n";
        else
            cout << (abs(r - l) / 2 - can_flip) + tt / 2 << "\n";
    }
}