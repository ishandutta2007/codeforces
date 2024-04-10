#include <bits/stdc++.h>

using namespace std;

bool pp(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int n;
    cin >> n;

    if (pp(n))
    {
        cout << "1\n";
        return 0;
    }

    if (n % 2 == 0)
    {
        cout << "2\n";
        return 0;
    }

    if (pp(n - 2))
    {
        cout << "2\n";
        return 0;
    }

    cout << "3\n";
}