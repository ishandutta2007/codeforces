#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n, m;
        scanf("%i%i", &n, &m);
        vector<int> arr(n);
        vector<bool> can(n);
        for (auto &x : arr)
            scanf("%i", &x);
        while (m--)
        {
            int a;
            scanf("%i", &a);
            can[a-1] = 1;
        }
        bool sorted = false;
        bool bad = false;
        while (!sorted)
        {
            sorted = true;
            for (int x = 0; x < n-1; x++)
                if (arr[x] > arr[x+1])
                {
                    sorted = false;
                    if (!can[x])
                        bad = true;
                    swap(arr[x], arr[x+1]);
                }
            if (bad)
                break;
        }
        if (bad)
            printf("NO\n");
        else
            printf("YES\n");
    }
}