#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long v[8][3];

inline long long dist(long long a[3], long long b[3])
{
    long long sm = 0;
    for (int i = 0; i < 3; ++i)
    {
        sm += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sm;
}

int match(long long d[], long long a)
{
    if (a == 0)
        return 0;
    for (int i = 0; i < 3; ++i)
        if (d[i] != a)
        {
            // printf("I DIFF %d %lld %lld\n", i, d[i], a);
            return 0;
        }
    for (int i = 3; i < 6; ++i)
        if (d[i] != a * 2)
        {
            // printf("I DIFF %d %lld %lld\n", i, d[i], a);
            return 0;
        }
    if (d[6] != a * 3)
    {
        // printf("I DIFF %d %lld %lld\n", 6, d[6], a);
        return 0;
    }
    return 1;
}

int rec(int dep)
{
    if (dep < 8)
    {
        sort(v[dep], v[dep] + 3);
        do
        {
            if (rec(dep + 1))
                return 1;
        }
        while (next_permutation(v[dep], v[dep] + 3));
        return 0;
    }
    else
    {
        // printf("CSOL!\n");
        long long d[8];
        for (int i = 1; i < 8; ++i)
            d[i - 1] = dist(v[0], v[i]);
        sort(d, d + 7);
        long long a = d[0];
        if (!match(d, a))
        {
            return false;
        }
        for (int s = 1; s < 8; ++s)
        {
            int l = 0;
            for (int j = 0; j < 8; ++j)
            {
                if (s == j)
                    continue;
                d[l++] = dist(v[s], v[j]);
            }
            sort(d, d + 7);
            if (!match(d, a))
            {
                return false;
            }
        }

        printf("YES\n");
        for (int i = 0; i < 8; ++i)
        {
            printf("%lld %lld %lld\n", v[i][0], v[i][1], v[i][2]);
        }
        return 1;
    }
}

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 3; ++j)
            scanf("%lld", &v[i][j]);
    }

    if (!rec(0))
    {
        printf("NO\n");
    }
    return 0;
}