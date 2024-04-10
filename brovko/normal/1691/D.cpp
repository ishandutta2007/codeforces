#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, a[200005], l[200005], r[200005], Min[200005][20], Max[200005][20], dp[200005];

int get(int l, int r, int t)
{
    r++;

    int L = r - l;
    int sz = dp[L];

    if(t)
        return max(Max[l][sz], Max[r - (1 << sz)][sz]);

    return min(Min[l][sz], Min[r - (1 << sz)][sz]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        stack <int> st;

        for(int i = 0; i < n; i++)
        {
            l[i] = -1;

            while(!st.empty() && a[st.top()] <= a[i])
            {
                if(a[st.top()] == a[i])
                    l[i] = st.top();

                st.pop();
            }

            if(l[i] == -1 && !st.empty())
                l[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i = n - 1; i >= 0; i--)
        {
            r[i] = n;

            while(!st.empty() && a[st.top()] <= a[i])
                st.pop();

            if(!st.empty())
                r[i] = st.top();

            st.push(i);
        }

        vector <int> ps(n + 1);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        for(int i = 0; i <= n; i++)
        {
            Min[i][0] = ps[i];
            Max[i][0] = ps[i];
        }

        for(int j = 1; j < 20; j++)
            for(int i = 0; i + (1 << j) <= n + 1; i++)
            {
                Min[i][j] = min(Min[i][j - 1], Min[i + (1 << j - 1)][j - 1]);
                Max[i][j] = max(Max[i][j - 1], Max[i + (1 << j - 1)][j - 1]);
            }

        for(int i = 2; i <= n + 1; i++)
            dp[i] = dp[i / 2] + 1;

        bool F = true;

        for(int i = 0; i < n; i++)
        {
            int psl = get(l[i] + 1, i, 0);
            int psr = get(i + 1, r[i], 1);

            if(psr - psl > a[i])
                F = false;
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}