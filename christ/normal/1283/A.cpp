#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int h, m;
        scanf("%i%i", &h, &m);
        if (h == 0 && m == 0)
            printf("0\n");
        else
        {
            int ans = 60 - m;
            h++;
            while (h < 24)
                h++, ans += 60;
            printf("%i\n", ans);
        }
    }
}