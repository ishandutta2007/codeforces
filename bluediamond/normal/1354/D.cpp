#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e6 + 7;
int n;
int q;
int t[N];

void add(int i, int x)
{
    while (i <= n)
    {
        t[i] += x;
        i += i & (-i);
    }
}

int get(int i)
{
    int sol = 0;
    while (i)
    {
        sol += t[i];
        i -= i & (-i);
    }
    return sol;
}

int fk(int k)
{
    int sol = 0, r = 0, step = (1 << 20);
    while (step)
    {
        if (r + step <= n && get(r + step) < k)
        {
            r += step;
        }
        step /= 2;
    }
    r++;
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x, 1);
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            add(x, 1);
        }
        else
        {
            x *= -1;
            x = fk(x);
            add(x, -1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (t[i])
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";
}