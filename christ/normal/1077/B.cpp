#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int k = 0;
    for (int x = 1; x < n-1; x++)
    {
        if (arr[x-1] && !arr[x] && arr[x+1])
            arr[x+1] ^= 1, k++;
    }
    printf("%i\n", k);
}