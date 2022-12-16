#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 5050;
const ll MOD = 1e9+7;

int8_t have[N][N];
int takenl[N][N];
int takenr[N][N];
vector<int> optionsl[N];
vector<int> optionsr[N];
ll total[N];
int cnt[N];

int n, m;

int a[N];

ll fac[N];
ll ifac[N];

ll modpow(ll b, ll p) {
    ll ans = 1;
    for (;p ;p/=2, b=b*b%MOD) {
        if (p&1) {
            ans = ans*b%MOD;
        }
    }
    return ans;
}

void setup() {
    fac[0] = ifac[0] = 1;
    for (int i=1; i<N; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        ifac[i] = ifac[i-1]*modpow(i, MOD-2)%MOD;
    }
}

ll choose(int n, int k) {
    return (fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

void solve(int fi, int hi, int center, int from) {
    if (!have[fi][hi]) return;
    --have[fi][hi];

    for (int i=1; i<=n; ++i) {
        optionsl[i].clear();
        optionsr[i].clear();
        cnt[i] = 0;
    }

    // DO NOT RETURN
    for (int i=1; i<center; ++i) {
        ++cnt[a[i]];
        if (have[a[i]][cnt[a[i]]] && !(from == 0 && a[i] == fi)) {
            optionsl[a[i]].push_back(cnt[a[i]]);
            takenl[a[i]][cnt[a[i]]] = 1;
        }
    }

    memset(cnt, 0, sizeof cnt);
    for (int i=n; i>center; --i) {
        ++cnt[a[i]];
        if (have[a[i]][cnt[a[i]]] && !(from == 1 && a[i] == fi)) {
            optionsr[a[i]].push_back(cnt[a[i]]);
            takenr[a[i]][cnt[a[i]]] = 1;
        }
    }

    int amt = 0;
    ll ways = 1;

    //cerr << "  CENTER " << center << endl;

    for (int i=1; i<=n; ++i) {
        if (optionsl[i].size() && optionsr[i].size()) {
            int ml = optionsl[i].size();
            int mr = optionsr[i].size();

            int contr = 0;

            for (auto& j : optionsl[i]) {
                //cerr << " J " << j << endl;
                contr += (mr - takenr[i][j]);
                //cerr << " :: " << mr << " - " << (int) takenl[i][j] << endl;
            }
            /*
            for (auto& j : optionsr[i]) {
                contr += (ml - takenl[i][j]);
                //cerr << " :: " << ml << " - " << (int) takenr[i][j] << endl;
            }
            */
            //cerr << " i " << i << " contr " << contr << " TWO " << endl;

            if (contr) {
                ways = ways*contr%MOD;
                amt += 2;
            } else {
                amt += 1;
                ways = ways*2%MOD;
            }
        } else if (optionsl[i].size() || optionsr[i].size()) {
            ++amt;
            int contr = max(optionsl[i].size(), optionsr[i].size());
            //cerr << " i " << i << " contr " << contr << endl;
            ways = ways*contr%MOD;
        }

        for (auto& j : optionsl[i]) {
            takenl[i][j] = 0;
        }
        for (auto& j : optionsr[i]) {
            takenr[i][j] = 0;
        }
    }

    total[amt+(fi != 0)] += ways;

    ++have[fi][hi];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setup();
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    for (int i=1; i<=m; ++i) {
        int f, h;
        cin >> f >> h;
        have[f][h] = 1;
    }
    have[0][0] = 1;
    total[0] = 1;
    for (int i=0; i<=n; ++i) {
        int cfront = 0, cback=0;
        for (int j=i; j>=1; --j) {
            cfront += a[j] == a[i];
        }
        for (int j=i; j<=n; ++j) {
            cback += a[j] == a[i];
        }

        solve(a[i], cfront, i, 0);
        //solve(a[i], cback, i, 1);
    }

    pii ans(0, 1);
    for (int i=1; i<=n; ++i) {
        if (total[i]) {
            ans = max(ans, pii(i, total[i]%MOD));
        }
    }
    cout << ans.first << " " << ans.second << endl;


    return 0;
}