#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int k;
        cin >> k;
        string old;
        cin >> old;
        int x = 0;
        while (true) {
            string nxt = old;
            for (int i=k-1; i>0; --i) {
                if (nxt[i-1] == 'A') {
                    nxt[i] = 'A';
                }
            }
            if (nxt == old) {
                break;
            }
            old = nxt;
            ++ x;
        }
        cout << x << "\n";
    }
    return 0;
}