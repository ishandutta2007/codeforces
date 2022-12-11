#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d, h, i;
    cin >> n >> d >> h;
    if (d > h * 2)
    {
        cout << -1 << endl;
        return 0;
    }
    if (n > 2 && d == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    if (d == h)
    {
        for (i = 0; i < h; i++)
        {
            cout << i + 1 << ' ' << i + 2 << endl;
        }
        for (i = h; i < n - 1; i++)
        {
            cout << 2 << ' ' << i + 2 << endl;
        }
    }
    else
    {
        for (i = 0; i < h; i++)
        {
            cout << i + 1 << ' ' << i + 2 << endl;
        }
        cout << 1 << ' ' << h + 2 << endl;
        for (i = h + 1; i < d; i++)
        {
            cout << i + 1 << ' ' << i + 2 << endl;
        }
        for (i = d; i < n - 1; i++)
        {
            cout << 1 << ' ' << i + 2 << endl;
        }
    }
    return 0;
}