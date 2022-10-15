#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
int q;
int a[N];
int nxt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    nxt[n] = n + 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] != a[i + 1])
        {
            nxt[i] = i + 1;
        }
        else
        {
            nxt[i] = nxt[i + 1];
        }
    }
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (x != a[l])
        {
            cout << l << "\n";
        }
        else
        {
            if (nxt[l] <= r)
            {
                cout << nxt[l] << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }

}