#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int x = 0; x < n; x += 2)
        ans += arr[x+1] - arr[x];
    printf("%i\n", ans);
}