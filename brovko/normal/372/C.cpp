#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, d, a[305], b[305], t[305], dp[150005][2];
stack <pair <int, int> > st1, st2;

void push(int x)
{
    st1.push({x, st1.empty() ? x : min(x, st1.top().y)});
}

int get()
{
    int ans = 1e9;

    if(st1.size())
        ans = min(ans, st1.top().y);

    if(st2.size())
        ans = min(ans, st2.top().y);

    return ans;
}

void pop()
{
    if(st2.empty())
    {
        while(st1.size())
        {
            st2.push({st1.top().x, st2.empty() ? st1.top().x : min(st1.top().x, st2.top().y)});
            st1.pop();
        }
    }

    st2.pop();
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;

    for(int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> t[i];
        a[i]--;
    }

    for(int i = 0; i < m; i++)
    {
        int D = 0;

        if(i)
            D = min(n * 1ll, d * 1ll * (t[i] - t[i - 1]));

        if(i)
            for(int j = 0; j <= min(n - 1, D - 1); j++)
                push(dp[j][0]);

        for(int j = 0; j < n; j++)
        {
            dp[j][1] = abs(j - a[i]);

            if(i)
            {
                if(j + D < n)
                    push(dp[j + D][0]);

                if(j - D - 1 >= 0)
                    pop();

                int x = get();

//                int x = get(max(0, j - D), min(n, j + D + 1));

//                int x = 1e9;
//
//                for(int k = max(0, j - D); k <= min(n - 1, j + D); k++)
//                    x = min(x, dp[k][0]);

                dp[j][1] += x;
            }
        }

        for(int j = 0; j < n; j++)
            dp[j][0] = dp[j][1];

        while(st1.size() || st2.size())
            pop();
    }

    long long ans = 1e9;

    for(int i = 0; i < n; i++)
        ans = min(ans, (long long)dp[i][0]);

    ans = -ans;

    for(int i = 0; i < m; i++)
        ans += b[i];

    cout << ans;
}