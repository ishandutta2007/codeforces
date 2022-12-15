#include <bits/stdc++.h>
using namespace std;

int arr[200000];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        arr[i] += arr[i - 1];
    int min_sum = 1000000000, ans = 0;
    for (int i = 1; i + k - 1 <= n; i++)
        if (arr[i + k - 1] - arr[i - 1] < min_sum)
            min_sum = arr[i + k - 1] - arr[i - 1], ans = i;
    cout << ans << endl;
}