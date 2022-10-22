#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string t, p;
int a[200005], used[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> p;

    int n = t.size();
    int m = p.size();

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    int L = 0;
    int R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        for(int i = 0; i < 200005; i++)
            used[i] = 0;

        for(int i = 0; i < M; i++)
            used[a[i]] = 1;

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(used[i] == 0 && x < m && t[i] == p[x])
                x++;
        }

        if(x >= m)
            L = M;
        else R = M;
    }

    cout << L;
}