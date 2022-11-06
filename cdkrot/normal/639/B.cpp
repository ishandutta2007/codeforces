#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, d, h;
    cin >> n >> d >> h;
    if (d + 1 > n)
    {
        cout << -1 << endl;
        return 0;
    }
    if (2 * h < d)
    {
        cout << -1 << endl;
        return 0;
    }
    if (h > d)
    {
        cout << -1 << endl;
        return 0;
    }
    if (d == h && h == 1 && n > 2)
    {
        cout << -1 << endl;
        return 0;
    }
    int c = 1;
    for (int i = 0; i < h; i++)
    {
        cout << c << " " << c + 1 << endl;
        c++;
    }
    if (h < d)
    {
        cout << 1 << " " << c + 1 << endl;
        c++;
    }
    for (int i = 0; i < d - h - 1; i++)
    {
        cout << c << " " << c + 1 << endl;
        c++;
    }
    while (c < n)
    {
        cout << 1 + (d == h) << " " << c + 1 << endl;
        c++;
    }
    return 0;
}