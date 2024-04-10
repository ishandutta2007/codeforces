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

void fwt(int *a, int n, int op) {
    for (int L = 2; L <= n; L <<= 1)
        for (int i = 0; i < n; i += L)
            for (int j = i; j < i + (L >> 1); ++j)
                a[j] += a[j + (L >> 1)] * op;
}


const int MAXn = 2e5 + 5;
ll d[MAXn];
int a[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        reverse(ALL(s));
        ll res = 0;
        for (char c : s)
            res = res * 2 + (c == '1');
        d[i] = res;
    }
    mt19937 rng(880301);
    vector<int> idx(n);
    for (int i = 1; i <= n; i++)
        idx[i - 1] = i;
    shuffle(ALL(idx), rng);
    ll bst = 0, ans = 0;
    for (int _i = 0; _i < n && _i < 20; _i++) {
        int t = idx[_i];    
        if (d[t] == 0)
            continue;
        vector<ll> base;
        for (ll x = d[t]; x > 0; x -= x & -x)
            base.pb(x & -x);
        int nn = SZ(base);
        for (int I = 0; I < (1<<nn); I++)
            a[I] = 0;
        for (int i = 1; i <= n; i++) {
            ll res = 0;
            for (int j = 0; j < nn; j++)
                if (d[i] & base[j])
                    res += (1<<j);
            a[res]++;
        }
        fwt(a, (1<<nn), 1);
        for (int I = 0; I < (1<<nn); I++)
            if (a[I] >= (n + 1) / 2) {
                ll res = 0, cnt = 0;
                for (int i = 0; i < nn; i++)
                    if ((I>>i)&1)
                        res += base[i], cnt++;
                if (cnt > bst)
                    bst = cnt, ans = res;
            }
    }  
    for (int i = 0; i < m; i++)
        if ((ans>>i)&1)
            cout << 1;
        else
            cout << 0;
    cout << "\n";
}