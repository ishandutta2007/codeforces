#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;

struct max2 {
    pii f, s;
    max2() :f(-1, -1), s(-1, -1) {}
    void insert(pii x) {
        if(x > f) {
            if(f.second != x.second) {
                swap(f, s);
            }
            f = x;
        } else if(x > s && x.second != f.second) {
            s = x;
        }
    }
};

const int NMAX = 300300;

int c[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    max2 m;
    for(int i=1;i<=n;++i) {
        cin >> c[i];
        m.insert(pii(i, c[i]));
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        if(m.f.second == c[i]) {
            ans = max(m.s.first-i, ans);
        } else {
            ans = max(m.f.first-i, ans);
        }
    }
    cout << ans << endl;
    return 0;
}