#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 200000 + 5;
const ll MOD = 1000000007;

ll add (ll a, ll b)
{
    a += b;
    a %= MOD;
    a += MOD;
    a %= MOD;
    return a;
}

ll mul (ll a, ll b)
{
    return a * (long long) b % MOD;
}

ll n;
ll v[N];
vector<ll>g[N];
ll dp[2][2][N];
ll cnt[2][2][N];
bool viz[N];

ll ans = 0;

ll tot[2][2];
ll tcn[2][2];

ll gt (ll nod, ll sgn, ll cnt1, ll s1, ll cnt2, ll s2)
{
    ll ans = mul (s2, cnt1);
    ans = add (ans, mul (s1, cnt2));
    if (sgn == 0)
    {
        ans = add (ans, -mul (cnt1, mul (cnt2, v[nod])));
    }
    else
    {
        ans = add (ans, mul (cnt1, mul (cnt2, v[nod])));
    }
    return ans;
}

ll sub[N];

void dfs (ll nod)
{
    sub[nod] = v[nod];
    viz[nod] = 1;
    dp[0][0][nod] = -v[nod];
    dp[1][1][nod] = v[nod];
    cnt[0][0][nod] = 1;
    cnt[1][1][nod] = 1;
    ll dad = -1;
    for (auto &nou : g[nod])
    {
        if (viz[nou])
        {
            dad = nou;
            continue;
        }
        sub[nod] += sub[nou];
        dfs (nou);
        for (ll st = 0; st < 2; st++)
        {
            for (ll now = 0; now < 2; now++)
            {
                cnt[st][now][nod] = add (cnt[st][now][nod], cnt[st][1 - now][nou]);
                if (now == 0)
                {
                    dp[st][now][nod] = add (dp[st][now][nod], -mul (v[nod], cnt[st][1 - now][nou]));
                }
                else
                {
                    dp[st][now][nod] = add (dp[st][now][nod], mul (v[nod], cnt[st][1 - now][nou]));
                }
                dp[st][now][nod] = add (dp[st][now][nod], dp[st][1 - now][nou]);
            }
        }
    }
    for (ll i = 0; i < 2; i++) for (ll j = 0; j < 2; j++) tot[i][j] = tcn[i][j] = 0;
    for (auto &nou : g[nod])
    {
        if (nou == dad) continue;
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                tot[i][j] = add (tot[i][j], dp[i][j][nou]);
                tcn[i][j] = add (tcn[i][j], cnt[i][j][nou]);
            }
        }
    }
    ll acum = 0;
    for (auto &nou : g[nod])
    {
        if (nou == dad) continue;
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                tot[i][j] = add (tot[i][j], -dp[i][j][nou]);
                tcn[i][j] = add (tcn[i][j], -cnt[i][j][nou]);
            }
        }
        for (ll now = 0; now < 2; now++)
        {
            ll cur1 = gt (nod, now, cnt[1][1 - now][nou], dp[1][1 - now][nou], tcn[0][1 - now], tot[0][1 - now]);
            ll cur2 = gt (nod, now, cnt[1][1 - now][nou], dp[1][1 - now][nou], tcn[1][1 - now], tot[1][1 - now]);
            acum = add (acum, cur1);
            acum = add (acum, cur2);
        }
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < 2; j++)
            {
                tot[i][j] = add (tot[i][j], dp[i][j][nou]);
                tcn[i][j] = add (tcn[i][j], cnt[i][j][nou]);
            }
        }
    }
    ans = add (ans, acum);
    ll fini = 0;
    fini = add (fini, dp[1][1][nod]);
    fini = add (fini, dp[1][1][nod]);
    fini = add (fini, -sub[nod]);
    ans = add (ans, fini);
}

int main()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }
    dfs (1);
    cout << ans << "\n";
    return 0;
}