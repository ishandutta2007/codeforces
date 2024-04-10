#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define vi vector <int>

using namespace std;

int n, q, t[400005][26], tx[400005], k[128];
string s;

void push(int v, int l, int r)
{
    if(tx[v] == 0)
        return;

    int m = (l + r) / 2;

    tx[2 * v + 1] = tx[v];
    tx[2 * v + 2] = tx[v];
    t[2 * v + 1][tx[v] - 'a'] = m - l;
    t[2 * v + 2][tx[v] - 'a'] = r - m;

    for(int i = 0; i < 26; i++)
        if(i != tx[v] - 'a')
        {
            t[2 * v + 1][i] = 0;
            t[2 * v + 2][i] = 0;
        }

    tx[v] = 0;
}

int get(int v, int l, int r, int L, int R, int x)
{
    if(L >= R)
        return 0;

    if(tx[v] > 0)
    {
        if(tx[v] == x)
            return R - L;
        else return 0;
    }

    if(L == l && R == r)
        return t[v][x - 'a'];

    int m = (l + r) / 2;

    return get(2 * v + 1, l, m, L, min(m, R), x) + get(2 * v + 2, m, r, max(L, m), R, x);
}

void update(int v, int l, int r, int L, int R, int val)
{
    if(L >= R)
        return;

    if(L == l && R == r)
    {
        tx[v] = val;

        for(int i = 0; i < 26; i++)
            t[v][i] = 0;

        t[v][val - 'a'] = r - l;

        return;
    }

    int m = (l + r) / 2;
    push(v, l, r);

    update(2 * v + 1, l, m, L, min(m, R), val);
    update(2 * v + 2, m, r, max(L, m), R, val);

    for(int i = 0; i < 26; i++)
        t[v][i] = t[2 * v + 1][i] + t[2 * v + 2][i];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> s;

    for(int i = 0; i < n; i++)
        update(0, 0, n, i, i + 1, s[i]);

    while(q--)
    {
        int l, r, t;
        cin >> l >> r >> t;

        l--;

        for(char i = 'a'; i <= 'z'; i++)
        {
            k[i] = get(0, 0, n, l, r, i);
        }

        if(t)
            for(char i = 'a'; i <= 'z'; i++)
            {
                update(0, 0, n, l, l + k[i], i);
                l += k[i];
            }
        else
            for(char i = 'z'; i >= 'a'; i--)
            {
                update(0, 0, n, l, l + k[i], i);
                l += k[i];
            }
    }

    for(int i = 0; i < n; i++)
        for(int j = 'a'; j <= 'z'; j++)
            if(get(0, 0, n, i, i + 1, j))
                cout << (char)j;
}