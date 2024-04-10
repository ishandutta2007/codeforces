#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    vector<int> cnt(n+1);
    vector<bool> taken(n+1);
    for (auto &x : arr)
        scanf("%i", &x), cnt[x]++;
    set<int> nohave;
    for (int x = 1; x <= n; x++)
        if (!cnt[x])
            nohave.insert(x);
    int ans = nohave.size();
    for (int x = 0; x < n; x++) 
    {
        int prev = arr[x];
        if (cnt[arr[x]] > 1)
        {
            if (!nohave.empty() && (*nohave.begin() < arr[x] || taken[arr[x]]))
            {
                arr[x] = *nohave.begin();
                nohave.erase(nohave.begin());
            }
            else if (!taken[arr[x]])
                taken[arr[x]] = 1;
            else
                abort();
        }
        else if (taken[arr[x]])
        {
            assert(nohave.size());
            arr[x] = *nohave.begin();
            nohave.erase(nohave.begin());
        }
        else
            taken[arr[x]] = 1;
        cnt[prev]--;
    }
    printf("%i\n", ans);
    for (auto &x : arr)
        printf("%i ", x);
    printf("\n");
}