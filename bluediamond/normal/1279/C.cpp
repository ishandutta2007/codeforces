#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
int m;
int a[N];
int pos[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        ll sol = 0, mx = 0;
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            int p = pos[x];
            if (p <= mx)
            {
                sol++;
            }
            else
            {
                mx = p;
                sol += 2 * (p - i) + 1;
            }
        }
        cout << sol << "\n";
    }

}