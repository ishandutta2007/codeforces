#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, a, b, turn;
    char ca = 'G', cb = 'B';
    string sol;
    cin >> n >> k >> a >> b;
    if (a > b)
    {
        turn = 0;
    }
    else
    {
        turn = 1;
    }
    turn ^= 1;
    while (a + b > 0)
    {
        turn ^= 1;
        if (turn == 0)
        {
            if (a == 0)
            {
                cout << "NO\n";
                return 0;
            }
            int take = min(k, a - b);
            take = max(take, 1);
            for (int i = 1; i <= take; i++)
            {
                sol += ca;
                a--;
            }
        }
        else
        {
            if (b == 0)
            {
                cout << "NO\n";
                return 0;
            }
            int take = min(k, b - a);
            take = max(take, 1);
            for (int i = 1; i <= take; i++)
            {
                sol += cb;
                b--;
            }
        }
    }
    cout << sol << "\n";
}