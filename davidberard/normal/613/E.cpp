#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

typedef long long Hsh;

const ll b = 2741;
const ll mod = 923242909;
const ll AMOD = 1e9+7;
const int N = 2020;

ll bpow[N], ibpow[N];

Hsh pre[2][N], suf[2][N];
Hsh tpre[N];
char s[2][N], t[N];
int n, m;

ll modpow(ll b, ll p, ll m=mod) {
    ll ans = 1;
    for (; p; p/=2, b=b*b%m) {
        if (p&1) ans = ans*b%m;
    }
    return ans;
}

void setup() {
    ibpow[0] = bpow[0] = 1;
    ibpow[1] = modpow(b, mod-2);
    for (int i=1; i<N; ++i) {
        bpow[i] = bpow[i-1]*b%mod;
        ibpow[i] = ibpow[i-1]*ibpow[1]%mod;
    }
}

void prep_hash() {
    for (int z=0; z<2; ++z) {
        pre[z][0] = 0;
        for (int i=1; i<=n; ++i) {
            pre[z][i] = (pre[z][i-1]*b + s[z][i-1])%mod;
        }
        suf[z][n] = 0;
        for (int i=n-1; i>=0; --i) {
            suf[z][i] = (suf[z][i+1]*b + s[z][i])%mod;
        }
    }
    for (int i=1; i<=m; ++i) {
        tpre[i] = (tpre[i-1]*b + t[i-1])%mod;
    }
}

// row z, [i, j)
Hsh forward_hash(int z, int i, int j) {
    //return (pre[z][j] - pre[z][i] + mod)*ibpow[i]%mod;
    return (pre[z][j] - bpow[j-i]*pre[z][i]%mod + mod)%mod;
}

Hsh backward_hash(int z, int i, int j) {
    /*
    ////////cerr << "   BH " << z << " " << i << " " << j << " : " << ibpow[n-j] << "*" << bpow[n-j] << " = " << ibpow[n-j]*bpow[n-j]%mod << endl;
    Hsh ans = (suf[z][i] - suf[z][j] + mod)*ibpow[n-j]%mod;
    ////////cerr << " .. " << ans << " : " << suf[z][i] << " " << suf[z][j] << " :: " << s[z][0]+s[z][1]*b << endl;
    return ans;
    */
    return (suf[z][i] - suf[z][j]*bpow[j-i]%mod + mod)%mod;
}

Hsh t_hash(int i, int j) {
    //return (tpre[j] - tpre[i] + mod)*ibpow[i]%mod;
    return (tpre[j] - tpre[i]*bpow[j-i]%mod + mod)%mod;
}

ll f[N][2][N], g[N][2][N], dp[N][2][N];

void gen_fg() {
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    g[n][0][m] = g[n][1][m] = 1;
    for (int i=0; i<n; ++i) {
        g[i][0][m] = g[i][1][m] = 1;
        f[i][0][0] = f[i][1][0] = 1;
        for (int j=1; i-j+1>=0 && 2*j<=m; ++j) {
            { // top to bottom
                ll xh = backward_hash(0, i+1-j, i+1)*bpow[j] + forward_hash(1, i+1-j, i+1);
                xh %= mod;
                ////////cerr << " : " << xh << " vs " << t_hash(0, j*2) << " ? " << backward_hash(0, i+1-j, i+j) << " " << forward_hash(1, i+1-j, i+1) << endl;
                if (xh == t_hash(0, j*2)) {
                    f[i][1][j*2] = 1;
                }
            }
            { // bottom to top
                ll xh = backward_hash(1, i+1-j, i+1)*bpow[j] + forward_hash(0, i+1-j, i+1);
                xh %= mod;
                ////////cerr << " : " << xh << " vs " << t_hash(0, j*2) << endl;
                if (xh == t_hash(0, j*2)) {
                    f[i][0][j*2] = 1;
                }
            }
        }

        //for (int j=1+(m/2==1); i+j-1<n && 2*j <= m; ++j) {
        for (int j=2; i+j-1<n && 2*j <= m; ++j) {
            { // top to bottom
                ll xh = forward_hash(0, i, i+j)*bpow[j] + backward_hash(1, i, i+j);
                xh %= mod;
                ////cerr << " ::: " << xh << " " << t_hash(m-2*j, m) << " : " << forward_hash(0, i, i+j) << " " << backward_hash(1, i, i+j) << endl;
                if (xh == t_hash(m-2*j, m)) {
                    g[i][0][m-j*2] = 1;
                }
            }
            { // bottom to top
                ll xh = forward_hash(1, i, i+j)*bpow[j] + backward_hash(0, i, i+j);
                xh %= mod;
                if (xh == t_hash(m-2*j, m)) {
                    g[i][1][m-j*2] = 1;
                }
            }
        }
        for (int j=0; j<=m; ++j) {
            ////cerr << " f[" << i << "][0][" << j << "] = " << f[i][0][j] << endl;
            ////cerr << " f[" << i << "][1][" << j << "] = " << f[i][1][j] << endl;
            ////cerr << " g[" << i << "][0][" << j << "] = " << g[i][0][j] << endl;
            ////cerr << " g[" << i << "][1][" << j << "] = " << g[i][1][j] << endl;
        }
    }
}

ll solve(const string &r1, const string &r2, const string &goal) {
    for (int i=0; i<r1.size(); ++i) {
        s[0][i] = r1[i];
        s[1][i] = r2[i];
    }
    for (int i=0; i<goal.size(); ++i) {
        t[i] = goal[i];
    }
    prep_hash();
    gen_fg();

    memset(dp, 0, sizeof dp);
    for (int i=0; i<n; ++i) {
        dp[i][0][0] = dp[i][1][0] = 1;
        for (int j=1; j<=m; ++j) {
            dp[i][0][j] = f[i][0][j];
            dp[i][1][j] = f[i][1][j];
        }
    }

    ll ans = 0;

    if (s[0][0] == t[0]) {
        dp[0][0][1] = 1;
    }
    if (s[1][0] == t[0]) {
        dp[0][1][1] = 1;
    }

    ans += g[0][0][0]%AMOD;
    ans += g[0][1][0]%AMOD;
    //cerr << "!! " << ans << endl;
    for (int j=0; j<=m; ++j) {
        ans += dp[0][0][j]*g[1][0][j]%AMOD;
        ans += dp[0][1][j]*g[1][1][j]%AMOD;
        //cerr << "   %0% " << dp[0][0][j]*g[1][0][j] << endl;
        //cerr << "   %1% " << dp[0][1][j]*g[1][1][j] << endl;
    }

    for (int i=1; i<n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (s[0][i] == t[j-1]) {
                dp[i][0][j] += dp[i-1][0][j-1];
            }
            if (s[1][i] == t[j-1]) {
                dp[i][1][j] += dp[i-1][1][j-1];
            }
            if (j>2 && s[0][i] == t[j-2] && s[1][i] == t[j-1]) {
                dp[i][1][j] += dp[i-1][0][j-2];
            }
            if (j>2 && s[1][i] == t[j-2] && s[0][i] == t[j-1]) {
                dp[i][0][j] += dp[i-1][1][j-2];
            }

            dp[i][0][j] %= AMOD;
            dp[i][1][j] %= AMOD;

            //cerr << "   $ dp[" << i << "][0][" << j << "] = " << dp[i][0][j] << " -> " << dp[i][0][j]*g[i+1][0][j] << endl;
            //cerr << "   $ dp[" << i << "][1][" << j << "] = " << dp[i][1][j] << " -> " << dp[i][1][j]*g[i+1][1][j] << endl;

            ans += dp[i][0][j]*g[i+1][0][j]%AMOD;
            ans += dp[i][1][j]*g[i+1][1][j]%AMOD;
        }
        ans += dp[i][0][0]*g[i+1][0][0]%AMOD;
        ans += dp[i][1][0]*g[i+1][1][0]%AMOD;
        //cerr << "      $ " << dp[i][0][0]*g[i+1][0][0]%AMOD << endl;
        //cerr << "      $ " << dp[i][1][0]*g[i+1][1][0]%AMOD << endl;
    }

    if (m == 4) {
        for (int i=0; i<n-1; ++i) {
            ans += AMOD - f[i][0][2]*g[i+1][0][2] - f[i][1][2]*g[i+1][1][2];
            //cerr << " : " << f[i][0][2]*g[i+1][0][2] << " " << f[i][1][2]*g[i+1][1][2] << endl;
            ans %= AMOD;
        }
    }

    return ans%AMOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    string r1, r2, goal;
    cin >> r1 >> r2 >> goal;
    n = r1.size();
    m = goal.size();
    string rgoal = goal;
    reverse(rgoal.begin(), rgoal.end());

    ll ans = solve(r1, r2, goal);

    //if (rgoal != goal) {
        reverse(r1.begin(), r1.end());
        reverse(r2.begin(), r2.end());
        ans += solve(r2, r1, goal);

        ////////cerr << "    ## " << r2 << endl;
        ////////cerr << "    ## " << r1 << endl;

        if (goal.size()%2 == 0) {
            //cerr << " init " << ans << endl;
            ////////cerr << " init " << ans << endl;
            for (int i=0; i<n; ++i) {
                for (int j=0; j<=goal.size(); j+=goal.size()) {
                    ans += AMOD*2 - f[i][0][j]*g[i+1][0][j] - f[i][1][j]*g[i+1][1][j];
                    ans %= AMOD;
                    //cerr << " " << i << " " << j << " -> " << ans << endl;
                }
            }
            ans += AMOD*2 - g[0][0][0] - g[0][1][0];
            ans %= AMOD;
            //cerr << " " << -1 << " " << 0 << " -> " << ans << endl;
        }
        if (goal.size() == 1) {
            ans = ans*modpow(2, AMOD-2, AMOD)%AMOD;
        }
    //}

    cout << ans%AMOD << "\n";
    return 0;
}