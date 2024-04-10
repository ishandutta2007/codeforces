#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll p[100002];
ll dp[100002][18];

void solve()
{
    int k, n; cin >> n >> k;
    if(k > 17)
    {
        cout << n << "\n";
        return;
    }
    else cout << dp[n][k] << "\n";
}

ll c(int l, int r)
{
    if(l > r) return INF;
    ll ret = 0;
    for(int i=l;i<=r;)
    {
        int nxt = r/(r/i);
        int x = 0;
        if(i >= l) x = nxt - i + 1;
        else if(nxt >= l) x = nxt - l + 1;
        ret += p[r/i] * x;
        i = nxt + 1;
    }
    return ret;
}

void dnc(int i, int l, int r, int optl, int optr)
{
    if(l > r) return;
    int mid = (l + r)/2;
    ll C = c(min(mid, optr) + 1, mid);
    dp[mid][i] = INF;
    int opt = optl;
    for(int j=min(optr, mid);j>=optl;j--)
    {
        if(C + dp[j][i-1] <= dp[mid][i])
        {
            dp[mid][i] = dp[j][i-1] + C;
            opt = j;
        }
        if(C == INF) C = p[mid / j];
        else C += p[mid / j];
    }

    dnc(i, l, mid-1, optl, opt);
    dnc(i, mid+1, r, opt, optr);
}

void PreComp()
{
    for(int i=1;i<=100000;i++) p[i] = i;
    for(int i=2;i<=100000;i++)
    {
        if(p[i] != i) continue;
        for(int j=i;j<=100000;j+=i)
        {
            p[j] *= i-1;
            p[j] /= i;
        }
    }
    for(int i=2;i<=100000;i++) p[i] += p[i-1];
    for(int i=1;i<=100000;i++) dp[i][1] = 1LL * i * (i + 1)/ 2;
    for(int i=2;i<=17;i++)
    {
        dnc(i, 1, 100000, 1, 100000);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    PreComp();
    while(t--){
        solve();
    }
}