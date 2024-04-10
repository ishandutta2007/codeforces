#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, p, a[500005], l[500005], r[500005];
string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;

    cin >> s >> t;

    stack <int> q;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
            q.push(i);

        else
        {
            a[i] = q.top();
            a[q.top()] = i;

            q.pop();
        }
    }

    for(int i = 0; i < n; i++)
    {
        l[i] = i - 1;
        r[i] = i + 1;
    }

    p--;

    for(int i = 0; i < m; i++)
    {
        if(t[i] == 'L')
            p = l[p];

        if(t[i] == 'R')
            p = r[p];

        if(t[i] == 'D')
        {
            if(s[p] == '(')
            {
                if(l[p] >= 0)
                    r[l[p]] = r[a[p]];

                if(r[a[p]] < n)
                    l[r[a[p]]] = l[p];

                if(r[a[p]] < n)
                    p = r[a[p]];
                else p = l[p];
            }
            else
            {
                p = a[p];

                if(l[p] >= 0)
                    r[l[p]] = r[a[p]];

                if(r[a[p]] < n)
                    l[r[a[p]]] = l[p];

                if(r[a[p]] < n)
                    p = r[a[p]];
                else p = l[p];
            }
        }
    }

    while(l[p] >= 0)
        p = l[p];

    while(p < n)
    {
        cout << s[p];
        p = r[p];
    }
}