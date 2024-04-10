#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 140582;
int n;
ll a[N];
ll b[N];
ll sol[N];
ll mx;

void push(int c) {
        c = n - c;
        for (int i = 0; i < n; i++) {
                b[i] = a[(i + c) % n];
        }
        for (int i = 0; i < n; i++) {
                a[i] = b[i];
        }
}

void revert_sol(int c) {
        for (int i = 0; i < n; i++) {
                b[i] = sol[(i + c) % n];
        }
        for (int i = 0; i < n; i++) {
                sol[i] = b[i];
        }
}


int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> a[i];
                mx = max(mx, a[i]);
        }
        if (mx == 0) {
                cout << "YES\n";
                for (int i = 0; i < n; i++) {
                        cout << 1 << " ";
                }
                cout << "\n";
                return 0;
        }
        int pos = -1;
        for (int i = 0; i < n; i++) {
                if (a[i] == mx && a[(i + n - 1) % n] < mx) {
                        pos = i;
                }
        }
        if (pos == -1) {
                cout << "NO\n";
                return 0;
        }
        push(n - 1 - pos);
        sol[n - 1] = a[n - 1];
        ll s = (ll) 1e11 / a[n - 1] * a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
                s += a[i];
                sol[i] = s;
        }
        revert_sol(n - 1 - pos);
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
                cout << sol[i] << " ";
        }
        cout << "\n";
}