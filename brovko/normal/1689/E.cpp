#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int used[30];

void dfs(int** g, int v)
{
    used[v] = 1;

    for(int i = 0; i < 30; i++)
        if(g[v][i] > 0 && used[i] == 0)
            dfs(g, i);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> cnt(30);
        int** g = new int* [30];
        int k0 = 0;

        for(int i = 0; i < 30; i++)
            g[i] = new int[30];

        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
                g[i][j] = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0)
            {
                k0++;
                a[i] = 1;
            }

            for(int j = 0; j < 30; j++)
                if(a[i] & (1 << j))
                    cnt[j]++;

            for(int j = 0; j < 30; j++)
                for(int k = 0; k < j; k++)
                    if((a[i] & (1 << j)) != 0 && (a[i] & (1 << k)) != 0)
                    {
                        g[j][k]++;
                        g[k][j]++;
                    }
        }

        int ans = 1e9;
        int I = 0, J = 0;

        for(int i = 0; i < n; i++)
        {
            int A = a[i];

            for(int j = 0; j <= 31; j++)
            {
                if(a[i] == 0)
                    break;

                for(int x = 0; x < 30; x++)
                    used[x] = 0;

                int kcomp = 0;

                for(int x = 0; x < 30; x++)
                    if(used[x] == 0 && cnt[x] > 0)
                    {
                        kcomp++;
                        dfs(g, x);
                    }

//                cout << i << ' ' << j << ' ' << j + k0 + kcomp - bool(cnt[0]) << endl;

                if(j + k0 + kcomp - bool(cnt[0] || kcomp == 1) < ans)
                {
                    ans = j + k0 + kcomp - bool(cnt[0] || kcomp == 1);
                    I = i;
                    J = j;
                }

                for(int x = 0; x < 30; x++)
                    if(a[i] & (1 << x))
                        cnt[x]--;

                for(int x = 0; x < 30; x++)
                    for(int y = 0; y < x; y++)
                        if((a[i] & (1 << x)) != 0 && (a[i] & (1 << y)) != 0)
                        {
                            g[x][y]--;
                            g[y][x]--;
                        }

                a[i]--;

                for(int x = 0; x < 30; x++)
                    if(a[i] & (1 << x))
                        cnt[x]++;

                for(int x = 0; x < 30; x++)
                    for(int y = 0; y < x; y++)
                        if((a[i] & (1 << x)) != 0 && (a[i] & (1 << y)) != 0)
                        {
                            g[x][y]++;
                            g[y][x]++;
                        }
            }

            for(int x = 0; x < 30; x++)
                if(a[i] & (1 << x))
                    cnt[x]--;

            for(int x = 0; x < 30; x++)
                for(int y = 0; y < x; y++)
                    if((a[i] & (1 << x)) != 0 && (a[i] & (1 << y)) != 0)
                    {
                        g[x][y]--;
                        g[y][x]--;
                    }

            a[i] = A;

            for(int x = 0; x < 30; x++)
                if(a[i] & (1 << x))
                    cnt[x]++;

            for(int x = 0; x < 30; x++)
                for(int y = 0; y < x; y++)
                    if((a[i] & (1 << x)) != 0 && (a[i] & (1 << y)) != 0)
                    {
                        g[x][y]++;
                        g[y][x]++;
                    }
        }

        cout << ans << "\n";

        if(ans == 0)
        {
            for(int i = 0; i < n; i++)
                cout << a[i] << ' ';

            cout << "\n";

            continue;
        }

        for(int x = 0; x < 30; x++)
            if(a[I] & (1 << x))
                cnt[x]--;

        for(int x = 0; x < 30; x++)
            for(int y = 0; y < x; y++)
                if((a[I] & (1 << x)) != 0 && (a[I] & (1 << y)) != 0)
                {
                    g[x][y]--;
                    g[y][x]--;
                }

        a[I] -= J;

        for(int x = 0; x < 30; x++)
            if(a[I] & (1 << x))
                cnt[x]++;

        for(int x = 0; x < 30; x++)
            for(int y = 0; y < x; y++)
                if((a[I] & (1 << x)) != 0 && (a[I] & (1 << y)) != 0)
                {
                    g[x][y]++;
                    g[y][x]++;
                }

        for(int i = 0; i < 30; i++)
            used[i] = 0;

        for(int i = 0; i < 30; i++)
        {
            if(used[i] == 0 && cnt[i] > 0)
            {
                dfs(g, i);

                if(i != 0)
                {
                    int j = 0;

                    while((a[j] & (1 << i)) == 0)
                        j++;

                    a[j]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}