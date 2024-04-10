#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

int main()
{
    long long c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;
    long long l = 0, r = (long long)2e18;
    if (w1 <= w2 && h1 >= h2)
    {
        cout << (c / w1) * h1;
        return 0;
    }
    if (w2 <= w1 && h2 >= h1)
    {
        cout << (c / w2) * h2;
    }
    if (c / w1 <= (long long)1e6)
    {
        long long ans = 0;
        for (int i = 0; i <= c / w1; i++)
        {
            ans = max(ans, i * h1 + ((c - i * w1) / w2) * h2);
        }
        cout << ans << endl;
        return 0;
    }
    if (c / w2 <= (long long)1e6)
    {
        long long ans = 0;
        for (int i = 0; i <= c / w2; i++)
        {
            ans = max(ans, i * h2 + ((c - i * w2) / w1) * h1);
        }
        cout << ans << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i <= max(w1, w2); i++)
    {
        if (i * w1 <= c)
        {
            ans = max(ans, i * h1 + ((c - i * w1) / w2) * h2);
        }
        if (i * w2 <= c)
        {
            ans = max(ans, i * h2 + ((c - i * w2) / w1) * h1);
        }
    }
    cout << ans << endl;
    return 0;
}