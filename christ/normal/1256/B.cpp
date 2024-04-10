#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n;
        scanf("%i", &n);
        vector<int> arr(n);
        for (auto &x : arr)
            scanf("%i", &x);
        int y = 0;
        while (y < n)
        {
            int ma = INT_MAX, mai = 0;
            for (int x = y; x < n; x++)
                if (arr[x] < ma)
                    ma = arr[x], mai = x;
            for (int x = mai; x > y; x--)
                swap(arr[x-1], arr[x]);
            if (y-1 >= 0 && arr[y-1] > arr[y])
                swap(arr[y-1], arr[y]);
            y = mai+1;
        }
        for (auto &x : arr)
            printf("%i ", x);
        printf("\n");
    }
}