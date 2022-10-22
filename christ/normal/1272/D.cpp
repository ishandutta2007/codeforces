#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n), prev(n);
    for (auto &x : arr)
        scanf("%i", &x);
    prev[0] = 1;
    int ans = 0;
    vector<int> ends;
    for (int x = 1; x < n; x++)
    {
        if (arr[x] <= arr[x-1])
        {
            ans = max(ans, prev[x-1]);
            ends.push_back(x-1);
            prev[x] = 1;
        }
        else
            prev[x] = prev[x-1] + 1;
    }
    ends.push_back(n-1);
    ans = max(ans, prev[n-1]);
    for (int x = 1; x < ends.size(); x++)
    {
        if ((ends[x-1]-1 >= 0 && arr[ends[x-1]-1] < arr[ends[x-1]+1]) || (ends[x-1]+2 < n && arr[ends[x-1]] < arr[ends[x-1]+2]))
            ans = max(ans, prev[ends[x-1]] - 1 + prev[ends[x]]);
    }
    cout << ans << endl;
}