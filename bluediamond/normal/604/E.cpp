#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int k;

int grundy(int a)
{
    if (k % 2 == 0)
    {
        if (a <= 2)
        {
            return a;
        }
        else
        {
            return 1 - a % 2;
        }
    }
    else
    {
        if (a <= 3)
        {
            return a % 2;
        }
        if (a == 4)
        {
            return 2;
        }
        if (a % 2 == 1)
        {
            return 0;
        }
        else
        {
            if (grundy(a / 2) == 1)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans ^= grundy(x);
    }
    if (ans)
    {
        cout << "Kevin\n";
    }
    else
    {
        cout << "Nicky\n";
    }
}