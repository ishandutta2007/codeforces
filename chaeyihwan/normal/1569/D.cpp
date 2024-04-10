#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x[200002], y[200002];
vector<int> inc[200002], inc2[200002];

ll f(ll x)
{
    return x * (x - 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        for(int i=1;i<=n;i++) cin >> x[i];
        for(int i=1;i<=m;i++) cin >> y[i];

        for(int i=1;i<=n;i++) inc[i].clear();
        for(int i=1;i<=m;i++) inc2[i].clear();
        for(int i=1;i<=k;i++)
        {
            int xp, yp; cin >> xp >> yp;
            int X = lower_bound(x + 1, x + n + 1, xp) - x;
            int Y = lower_bound(y + 1, y + m + 1, yp) - y;
            if(x[X] != xp) inc[X].push_back(Y);
            if(y[Y] != yp) inc2[Y].push_back(X);
        }
        for(int i=1;i<=n;i++) sort(inc[i].begin(), inc[i].end());
        for(int i=1;i<=m;i++) sort(inc2[i].begin(), inc2[i].end());
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            ans += f(inc[i].size());
            int cnt = 1;
            for(int j=1;j<inc[i].size();j++)
            {
                if(inc[i][j] != inc[i][j-1])
                {
                    ans -= f(cnt);
                    cnt = 1;
                }
                else cnt++;
            }
            ans -= f(cnt);
        }
        for(int i=1;i<=m;i++)
        {
            ans += f(inc2[i].size());
            int cnt = 1;
            for(int j=1;j<inc2[i].size();j++)
            {
                if(inc2[i][j] != inc2[i][j-1])
                {
                    ans -= f(cnt);
                    cnt = 1;
                }
                else cnt++;
            }
            ans -= f(cnt);
        }
        cout << ans << "\n";
    }

}