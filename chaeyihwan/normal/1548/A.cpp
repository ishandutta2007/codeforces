#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[200002], f[200002];


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        int s, e; cin >> s >> e;
        if(s < e) swap(s, e);
        f[s]++;
        f[e]++;
        cnt[s]++;
        if(f[e] - cnt[e] == 1) ans++;
    }

    int q; cin >> q;
    for(int i=1;i<=q;i++)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int s, e; cin >> s >> e;
            if(s < e) swap(s, e);
            f[s]++;
            f[e]++;
            cnt[s]++;
            if(f[e] - cnt[e] == 1) ans++;
        }
        if(t == 2)
        {
            int s, e; cin >> s >> e;
            if(s < e) swap(s, e);
            f[s]--;
            f[e]--;
            cnt[s]--;
            if(f[e] == cnt[e]) ans--;
        }
        if(t == 3)
        {
            cout << n - ans << "\n";
        }
    }
}