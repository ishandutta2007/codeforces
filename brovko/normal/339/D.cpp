#include <bits/stdc++.h>
#define li long long

using namespace std;
const int N = (1 << 17);

int t[4 * N];

void upd(int v, int l, int r, int pos, int val, bool f)
{
    if(r - l == 1)
    {
        t[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        upd(2 * v + 1, l, m, pos, val, f ^ 1);
    else upd(2 * v + 2, m, r, pos, val, f ^ 1);

    if(f)
        t[v] = (t[2 * v + 1] | t[2 * v + 2]);
    else t[v] = (t[2 * v + 1] ^ t[2 * v + 2]);
}

main()
{
    int n, m;
    cin >> n >> m;

    vector <int> a(1 << n);

    for(int i = 0; i < (1 << n); i++)
        cin >> a[i];

    bool f = n % 2;

    for(int i = 0; i < (1 << n); i++)
        upd(0, 0, (1 << n), i, a[i], f);

    while(m--)
    {
        int i, x;
        cin >> i >> x;

        upd(0, 0, (1 << n), i - 1, x, f);

        cout << t[0] << "\n";
    }
}