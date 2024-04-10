#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
int q;
int m;
int a[N];
int t[N];
int l[N];
int r[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t[i] >> l[i] >> r[i];
    }
    while (m--)
    {
        int p;
        cin >> p;
        for (int i = q; i >= 1; i--)
        {
            if (l[i] <= p && p <= r[i])
            {
                if (t[i] == 2)
                {
                    p = r[i] - (p - l[i]);
                }
                else
                {
                    if (p == l[i])
                    {
                        p = r[i];
                    }
                    else
                    {
                        p--;
                    }
                }
            }
        }
        cout << a[p] << " ";
    }
    cout << "\n";
}