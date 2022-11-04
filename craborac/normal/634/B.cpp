#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long s, x;
    cin >> s >> x;
    int num = 0;
    for (int i = 0; i < 60; i++)
    {
        if ((1ll << i) & x)
            num++;
    }
    if ((s - x) % 2 == 0)
    {
        //cout << (1ll << num) << endl;
        long long a = (s - x) / 2;
        if (a & x)
            cout << 0 << endl;
        else
            cout << (1ll << num) - 2 * (int)(a == 0) << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}