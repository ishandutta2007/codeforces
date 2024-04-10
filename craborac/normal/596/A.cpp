#include <bits/stdc++.h>

using namespace std;

int x[4], y[4];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    if (n == 1)
    {
        cout << -1 << endl;
    }
    else if (n == 2)
    {
        if (x[0] != x[1] && y[0] != y[1])
        {
            cout << abs(x[1] - x[0]) * abs(y[0] - y[1]) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (x[i] != x[j] && y[i] != y[j])
                {
                    cout << abs(x[i] - x[j]) * abs(y[i] - y[j]) << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}