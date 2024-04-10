#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    long long s = 0;
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int x = 0; x < k; x++)
    {
        if (x >= arr.size())
            printf("0\n");
        else
        {
            printf("%lli\n", arr[x] - s);
            s = arr[x];
        }
    }
}