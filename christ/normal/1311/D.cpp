#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    vector<vector<int>> sieve(20000);
    for (int x = 1; x < sieve.size(); x++)
    {
        for (int y = x; y < sieve.size(); y += x)
            sieve[y].push_back(x);
    }
    while (t--)
    {
        int a, b, c;
        scanf("%i%i%i", &a, &b, &c);
        int ma = INT_MAX;
        int _a = 0, _b = 0, _c = 0;
        for (int cc = 1; cc < 15000; cc++)
        {
            for (auto &bb : sieve[cc])
                for (auto &aa : sieve[cc])
                {
                    if (bb < aa)
                        break;
                    if (bb % aa == 0)
                    {
                        int v = abs(cc - c) + abs(bb - b) + abs(aa - a);
                        if (v < ma)
                            ma = v, _a = aa, _b = bb, _c = cc;
                    }
                }
        }
        printf("%i\n%i %i %i\n", ma, _a, _b, _c);
    }
}