#include <bits/stdc++.h>

using namespace std;

struct op
{
    int t, i, j;
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> cnt(200005);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x), cnt[x]++;
    int mai = 0;
    for (int x = 0; x < cnt.size(); x++)
        if (cnt[mai] < cnt[x])
            mai = x;
    int y = 0;
    for (; y < n; y++)
        if (arr[y] == mai)
            break;
    vector<op> ops;
    for (int z = y-1; z >= 0; z--)
    {
        if (arr[z] == arr[z+1])
            continue;
        else if (arr[z] < arr[z+1])
            ops.push_back({1, z+1, z+2});
        else
            ops.push_back({2, z+1, z+2});
        arr[z] = arr[z+1];
    }
    for (int z = y+1; z < n; z++)
    {
        if (arr[z] == arr[z-1])
            continue;
        else if (arr[z] < arr[z-1])
            ops.push_back({1, z+1, z});
        else
            ops.push_back({2, z+1, z});
        arr[z] = arr[z-1];
    }
    printf("%lu\n", ops.size());
    for (auto &x : ops)
        printf("%i %i %i\n", x.t, x.i, x.j);
}