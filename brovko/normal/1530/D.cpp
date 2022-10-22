#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005], used[200005], c[200005], k[200005], ans;

void dfs(int v)
{
    used[v] = 1;

    if(b[v] == 0 && c[a[v]] == 0)
    {
        b[v] = a[v] + 1;
        c[a[v]] = 1;
        ans++;
    }

    if(used[a[v]] == 0)
        dfs(a[v]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        ans = 0;

        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;

            b[i] = 0;
            used[i] = 0;
            c[i] = 0;
            k[i] = 0;
        }

        for(int i = 0; i < n; i++)
            k[a[i]]++;

        for(int i = 0; i < n; i++)
            if(used[i] == 0 && k[i] == 0)
                dfs(i);
                
        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                dfs(i);

        cout << ans << "\n";

        set <int> q;

        for(int i = 0; i < n; i++)
            if(c[i] == 0)
                q.insert(i);

        for(int i = 0; i < n; i++)
            if(b[i] == 0 && c[i] == 0)
            {
                int x = *(q.begin());

                if(x == i)
                    x = (*q.rbegin());

                b[i] = x + 1;
                c[x] = 1;

                q.erase(x);
            }

        for(int i = 0; i < n; i++)
            if(b[i] == 0)
            {
                int x = *(q.begin());

                if(x == i)
                    x = (*q.rbegin());

                b[i] = x + 1;
                c[x] = 1;

                q.erase(x);
            }

        for(int i = 0; i < n; i++)
            cout << b[i] << ' ';

        cout << "\n";
    }
}