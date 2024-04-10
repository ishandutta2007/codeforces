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
        vector<int> ans;
        ans.push_back(0);
        for (int prev = n+1; prev > 1;)
        {
            int goal = n / (prev-1);
            ans.push_back(goal);
            int l = 1, r = prev-1;
            while (l <= r)
            {
                int m = l+r>>1;
                if (n / m == goal) // divide smaller
                    r = m-1;
                else
                    l = m+1;
            }
            prev = l;
        }
        sort(ans.begin(), ans.end());
        printf("%lu\n", ans.size());
        for (auto &x : ans)
            printf("%i ", x);
        printf("\n");
    }
}