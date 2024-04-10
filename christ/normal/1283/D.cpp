#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    set<int> arr;
    while (n--)
    {
        int x;
        scanf("%i", &x);
        arr.insert(x);
    }
    set<int> used;
    for (auto &x : arr)
        used.insert(x);
    long long ans = 0;
    vector<int> po;
    po.reserve(m);
    for (int x = 1;; x++)
    {
        for (auto it = arr.begin(); it != arr.end();)
        {
            int y = *it;
            bool good = false;
            if (used.find(y+x) == used.end())
                used.insert(y+x), po.push_back(y+x), ans += x, good = true;
            if (po.size() == m)
                break;
            if (used.find(y-x) == used.end())
                used.insert(y-x), po.push_back(y-x), ans += x, good = true;
            if (po.size() == m)
                break;
            if (!good)
                it = arr.erase(it);
            else
                ++it;
        }
        if (po.size() == m)
            break;
    }
    printf("%lli\n", ans);
    for (auto &x : po)
        printf("%i ", x);
    printf("\n");
}