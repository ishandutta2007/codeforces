#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int dcount[10];
        memset(dcount, 0, sizeof dcount);
        string s;
        cin >> s;
        int sm = 0;
        for (auto& c : s) {
            dcount[c-'0']++;
            sm += c-'0';
        }
        bool z=0, e=0, t=0;
        z = dcount[0] != 0;
        e = (dcount[0] > 1) || dcount[2] || dcount[4] || dcount[6] || dcount[8];
        t = sm%3 == 0;
        cout << (z && e && t ? "red" : "cyan") << "\n";
    }
    return 0;
}