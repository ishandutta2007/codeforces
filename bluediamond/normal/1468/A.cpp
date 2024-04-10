/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 500002;

int t;

int n;

int a[N_MAX];

vector <int> BIT[N_MAX];

vector <int> updates[N_MAX];

void update (int a, int b, int val)
{
    for(int i = a; i <= n; i += i & -i)
    {
        int l = 1, r = updates[i].size() + 1;
        while(l < r)
        {
            int mid = ((l + r) >> 1);
            if(b <= updates[i][mid - 1])
                r = mid;
            else
                l = mid + 1;
        }
        int b1 = l;
        for(int j = b1; j <= (int)BIT[i].size(); j += j & -j)
            BIT[i][j - 1] = max(BIT[i][j - 1], val);
    }
}

int query (int a, int b)
{
    int ans = 0;
    for(int i = a; i >= 1; i -= i & -i)
    {
        int l = 0, r = updates[i].size();
        while(l < r)
        {
            int mid = ((l + r + 1) >> 1);
            if(updates[i][mid - 1] <= b)
                l = mid;
            else
                r = mid - 1;
        }
        int b1 = l;
        for(int j = b1; j >= 1; j -= j & -j)
            ans = max(ans, BIT[i][j - 1]);
    }
    return ans;
}

int st[N_MAX];
int lg;

int dp[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j += j & -j)
            {
                updates[j].push_back(a[i]);
                BIT[j].push_back(0);
            }
        }
        for(int i = 1; i <= n; i++)
            sort(updates[i].begin(), updates[i].end());
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            while(lg > 0 && a[i] >= a[st[lg]])
                lg--;
            dp[i] = query(i - 1, a[i]) + 1;
            if(st[lg] > 0)
                dp[i] = max(dp[i], query(st[lg], a[i]) + 2);
            ans = max(ans, dp[i]);
            update(i, a[i], dp[i]);
            st[++lg] = i;
        }
        lg = 0;
        for(int i = 1; i <= n; i++)
        {
            BIT[i].clear();
            updates[i].clear();
        }
        cout << ans << "\n";
    }
    return 0;
}