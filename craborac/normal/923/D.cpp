#include <bits/stdc++.h>

using namespace std;

string s[2];
int a[2][(int)4e5 + 10];
int b[2][(int)4e5 + 10];

void init(int v, int l, int r, int t)
{
    if (r - l == 1)
    {
        if (s[t][l] == 'B' || s[t][l] == 'C')
            a[t][v] = 1;
        else
            a[t][v] = 0;
        return;
    }
    int m = (l + r) / 2;
    init(2 * v + 1, l, m, t);
    init(2 * v + 2, m, r, t);
    a[t][v] = a[t][2 * v + 1] + a[t][2 * v + 2];
}

int get(int v, int l, int r, int q, int w, int t)
{
    if (l >= w || q >= r)
        return 0;
    if (q <= l && r <= w)
        return a[t][v];
    int m = (l + r) / 2;
    return get(2 * v + 1, l, m, q, w, t) + get(2 * v + 2, m, r, q, w, t);
}

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s[0] >> s[1];
    int n = s[0].size();
    int m = s[1].size();
    init(0, 0, n, 0);
    init(0, 0, m, 1);
    b[0][0] = 0;
    b[1][0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[0][i] == 'A')
            b[0][i + 1] = b[0][i] + 1;
        else
            b[0][i + 1] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (s[1][i] == 'A')
            b[1][i + 1] = b[1][i] + 1;
        else
            b[1][i + 1] = 0;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int q, w, e, r;
        cin >> q >> w >> e >> r;
        q--;
        e--;
        int x = get(0, 0, n, q, w, 0);
        int y = get(0, 0, m, e, r, 1);
        //cerr << endl << x << " " << y << endl;
        if (x <= y && (x + y) % 2 == 0)
        {
            //cerr << b[0][w] << " " << b[1][r] << endl;
            int b0 = min(b[0][w], w - q);
            int b1 = min(b[1][r], r - e);
            if (b0 == b1 && b0 >= w - q && y > 0)
                cout << 0;
            else if (b0 > b1 && b0 % 3 != b1 % 3 && x == y)
                cout << 0;
            else if (b0 < b1)
                cout << 0;
            else
                cout << 1;
        }
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}