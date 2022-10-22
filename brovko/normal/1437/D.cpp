#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[200005], d[200005];

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
        {
            cin >> a[i];
            a[i]--;
        }

        queue <int> q;
        q.push(0);

        int r = 1;

        while(!q.empty())
        {
            int y = q.front();
            q.pop();

            if(r < n)
            {
                d[r] = d[y] + 1;
                q.push(r);
                r++;
            }

            while(r < n && a[r] > a[r - 1])
            {
                d[r] = d[y] + 1;
                q.push(r);
                r++;
            }
        }

        cout << d[n - 1] << "\n";
    }
}