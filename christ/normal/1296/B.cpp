#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int s;
        scanf("%i", &s);
        long long ans = 0;
        while (s >= 10)
        {
            long long c = s / 10;
            ans += c * 10;
            s %= 10;
            s += c;
        }
        printf("%lli\n", ans + s);
    }
}