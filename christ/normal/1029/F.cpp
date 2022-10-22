#include <bits/stdc++.h>

using namespace std;

vector<long long> factor(long long a)
{
    vector<long long> res;
    long long sqa = sqrt(a);
    for (long long x = 1; x <= sqa; x++)
        if (a % x == 0)
            res.push_back(x);
    return res;
}

int main()
{
    long long a, b;
    scanf("%lli%lli", &a, &b);
    long long c = a + b;
    vector<long long> fa = factor(a), fb = factor(b), fc = factor(c);
    long long ans = LLONG_MAX;
    for (long long &x : fc)
    {
        for (long long &y : fa)
            if (y <= x && a / y <= c / x)
                goto NXT;
        for (long long &y : fb)
            if (y <= x && b / y <= c / x)
                goto NXT;
        continue;
NXT:;
        ans = min(ans, x + c / x);
    }
    ans *= 2;
    printf("%lli\n", ans);
}