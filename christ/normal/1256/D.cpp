#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n;
        long long k;
        scanf("%i%lli", &n, &k);
        vector<char> s(n);
        for (auto &x : s)
            scanf(" %c", &x);
        deque<int> zer;
        for (int x = 0; x < n; x++)
            if (s[x] == '0')
                zer.push_back(x);
        for (int x = 0; x < n; x++)
        {
            if (s[x] == '1')
            {
                while (!zer.empty() && zer.front() <= x)
                    zer.pop_front();
                if (!zer.empty())
                {
                    int o = zer.front();
                    zer.pop_front();
                    if (o-x <= k)
                    {
                        swap(s[x], s[o]);
                        k -= o-x;
                    }
                    else
                    {
                        swap(s[o], s[o-k]);
                        k = 0;
                    }

                }
            }
        }
        for (auto &x : s)
            printf("%c", x);
        printf("\n");
    }
}