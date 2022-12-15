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


const int C = 3000000;
int a[212345], cnt[3123456], d[212345], valid[212345];
pii p[2 * C];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (cnt[a[i]] == 0)
            valid[i] = 1;
        cnt[a[i]]++, d[i] = i;
    }
    sort(d + 1, d + 1 + n, [](int x, int y) { return a[x] < a[y]; });

    vector<int> v;
    for (int i = 1; i <= n && SZ(v) < 4; ) {
        if (i < n && a[d[i]] == a[d[i + 1]])
            v.pb(d[i]), v.pb(d[i + 1]), p[a[d[i]] * 2] = {d[i], d[i + 1]}, i += 2;
        else
            i++;
    }
    if (SZ(v) == 4) {
        cout << "YES" << endl;
        cout << v[0] << " " << v[2] << " " << v[1] << " " << v[3] << endl;
        return 0;
    }
    
    int N = min(n, 5000);
    for (int i = 1; i <= N; i++)
        if (valid[i] == 1)
            for (int j = 1; j < i; j++)
                if (valid[j] == 1) {
                    ll s = a[i] + a[j];
                    if (p[s].X != 0) {
                        cout << "YES" << endl;
                        cout << p[s].X << " " << p[s].Y << " " << i << " " << j << endl;
                        return 0;
                    }
                    else
                        p[s] = {i, j};
                }
    cout << "NO" << endl;
}