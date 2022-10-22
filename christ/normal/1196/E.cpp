#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int b, w;
        scanf("%i%i", &b, &w);
        vector<pair<int,int>> arr;
        int st = (b > w ? 3 : 2);
        for (int x = st; w > 0 && b > 0; (x & 1) ? w-- : b--, x++)
        {
            arr.push_back({x, 3});
        }
        int mx = arr.back().first;
        if (b > 0)
        {
            for (int x = st; x <= mx && b; x += 2, b--)
                arr.push_back({x, 2});
            for (int x = st; x <= mx && b; x += 2, b--)
                arr.push_back({x, 4});
            if (b)
                arr.push_back({mx+1, 3}), b--;
            if (b)
                arr.push_back({st-1, 3}), b--;
        }
        if (w > 0)
        {
            for (int x = st; x <= mx && w; x += 2, w--)
                arr.push_back({x, 2});
            for (int x = st; x <= mx && w; x += 2, w--)
                arr.push_back({x, 4});
            if (w)
                arr.push_back({mx+1, 3}), w--;
            if (w)
                arr.push_back({st-1, 3}), w--;
        }
        if (w || b)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for (auto &x : arr)
                printf("%i %i\n", x.first, x.second);
        }
    }
}