#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> a(n), b(n);
    for (auto &x : a)
        scanf("%i", &x);
    for (auto &x : b)
        scanf("%i", &x);
    map<pair<int,int>,int> cnt;
    int ze = 0, cc = 0;
    for (int x = 0; x < n; x++)
    {
        int bb = b[x], aa = a[x];
        if (!aa)
        {
            if (!bb)
                cc++;
            continue;
        }
        else if (!bb)
        {
            ze++;
            continue;
        }
        int g = __gcd(aa, bb);
        aa /= g;
        bb /= g;
        cnt[{aa, bb}]++;
    }
    int ans = ze;
    for (auto &x : cnt)
        ans = max(ans, x.second);
    printf("%i\n", ans + cc);
}