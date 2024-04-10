#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        string p, h;
        cin >> p >> h;
        int amt[256];
        memset(amt, 0, sizeof amt);
        for (int i=0; i<p.size(); ++i) {
            ++amt[p[i]];
        }
        bool good = false;
        for (int i=0; i+p.size()<=h.size(); ++i) {
            int q[256];
            memset(q, 0, sizeof q);
            for (int j=0; j<p.size(); ++j) {
                q[h[i+j]]++;
            }
            bool z = true;
            for (int j=0; j<256; ++j) {
                z &= q[j] == amt[j];
            }
            if (z) {
                good = true;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}