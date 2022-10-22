#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


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

        li s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        queue <li> q;
        q.push(s);

        map <li, int> m;

        for(int i = 0; i < n; i++)
            m[a[i]]++;

        int F = 1;

        while(!q.empty())
        {
            li x = q.front();
            q.pop();

            if(m[x])
            {
                m[x]--;
                continue;
            }

            if(x == 1 || q.size() > 100 * n + 100)
            {
                F = 0;
                break;
            }

            q.push(x / 2);
            q.push((x + 1) / 2);
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}