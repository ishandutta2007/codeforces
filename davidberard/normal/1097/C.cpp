#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 500500;

int n;
string s[N];

int lft[N], rght[N], zero;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> s[i];

        int l = 0, r = 0, ml = 0, mr = 0;
        for (int j=0; j<s[i].size(); ++j) {
            l += (s[i][j] == ')' ? -1 : 1);
            ml = min(ml, l);
        }
        for (int j=s[i].size()-1; j>=0; --j) {
            r += (s[i][j] == ')' ? 1 : -1);
            mr = min(mr, r);
        }

        if (mr < 0 && ml < 0) continue;
        if (mr == 0 && ml == 0) {
            ++zero;
            continue;
        }

        if (mr == 0) {
            lft[-ml]++;
        }
        else if (ml == 0) {
            rght[-mr]++;
        }
    }
    ll ans = zero/2;
    for (int i=1; i<N; ++i) {
        ans += min(lft[i], rght[i]);
    }
    cout << ans << "\n";
    return 0;
}