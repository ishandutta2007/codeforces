#include <bits/stdc++.h>

using namespace std;

int n;
string s[30], t[30];

void rotate()
{
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int x = 2 * i - (n - 1);
            int y = 2 * j - (n - 1);
            char c = s[i][j];
            swap(x, y);
            x *= -1;
            int i1 = ((n - 1) + x) / 2;
            int j1 = ((n - 1) + y) / 2;
            swap(x, y);
            x *= -1;
            int i2 = ((n - 1) + x) / 2;
            int j2 = ((n - 1) + y) / 2;
            swap(x, y);
            x *= -1;
            int i3 = ((n - 1) + x) / 2;
            int j3 = ((n - 1) + y) / 2;
            s[i][j] = s[i1][j1];
            s[i1][j1] = s[i2][j2];
            s[i2][j2] = s[i3][j3];
            s[i3][j3] = c;
        }
    }
}

void swapx()
{
    for (int i = 0; i < n - 1 - i; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(s[i][j], s[n - 1 - i][j]);
        }
    }
}

void swapy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - j; j++)
        {
            swap(s[i][j], s[i][n - 1 - j]);
        }
    }
}

void check()
{
    bool d = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] != t[i][j])
            {
                d = 0;
                break;
            }
        }
        if (!d)
            break;
    }
    if (d)
    {
        cout << "Yes" << endl;
        exit(0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int q = 0; q < 4; q++)
    {
        check();
        swapx();
        check();
        swapy();
        check();
        swapx();
        check();
        swapy();
        rotate();
        /*
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << "\n";
        }
        cout << endl;
        //*/
    }
    cout << "No" << endl;
    return 0;
}