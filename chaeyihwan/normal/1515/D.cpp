#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll c[200002];
int cnt[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, l, r; cin >> n >> l >> r;
        for(int i=1;i<=n;i++) cin >> c[i];

        int ans = 0, tmp1 = 0, tmp2 = 0;
        for(int i=1;i<=n;i++) cnt[i] = 0;
        for(int i=1;i<=l;i++)
        {
            cnt[c[i]]++;
        }

        for(int i=l+1;i<=n;i++)
        {
            cnt[c[i]]--;
        }

        for(int i=1;i<=n;i++)
        {
            if(l < r && cnt[i] < 0)
            {
                tmp1 += abs(cnt[i])/2;
            }
            if(l > r  && cnt[i] > 0)
            {
                tmp1 += abs(cnt[i])/2;
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i] < 0) cnt1 += abs(cnt[i]);
            if(cnt[i] > 0) cnt2 += cnt[i];
        }

        if(l < r)
        {
            cnt1 -= min(r - l, tmp1 * 2);
            ans += min((r - l)/2, tmp1);
        }
        if(l > r)
        {
            cnt2 -= min(l - r, tmp1 * 2);
            ans += min((l - r)/2, tmp1);
        }

        cout << ans + max(cnt1, cnt2) << "\n";
    }
}