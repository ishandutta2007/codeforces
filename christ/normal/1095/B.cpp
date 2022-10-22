#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, ma = INT_MIN, macnt = 0, mi = INT_MAX, micnt = 0;
    scanf("%i", &n);
    if (n == 1 || n == 2)
        return 0 * printf("0\n");
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    int ans = arr.back() - arr[0];
    ans = min(ans, arr.back() - arr[1]);
    ans = min(ans, arr[n-2] - arr[0]);
    cout << ans << endl; 
}