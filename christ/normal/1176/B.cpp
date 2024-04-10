#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);
        int cnt[3] = {0, 0, 0};
        int a;
        while (n--)
        {
            scanf("%i", &a);
            cnt[a%3]++;
        }
        printf("%i\n", cnt[0] + max(min(cnt[1], cnt[2]) + abs(cnt[1] - cnt[2]) / 3, cnt[1] / 3 + cnt[2] / 3 + min(cnt[1] % 3, cnt[2] % 3)));
    }
}