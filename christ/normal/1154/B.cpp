#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    set<int> arr;
    while (n--)
    {
        int a;
        scanf("%i", &a);
        arr.insert(a);
    }
    if (arr.size() == 1)
        printf("0\n");
    else if (arr.size() == 2)
    {
        int dd = *prev(arr.end()) - *arr.begin();
        printf("%i\n", dd & 1 ? dd : dd / 2);
    }
    else if (arr.size() == 3)
    {
        int d = (*prev(arr.end()) - *arr.begin()) / 2;
        if (arr.count(*arr.begin() + d) && arr.count(*prev(arr.end()) - d))
            printf("%i\n", d);
        else
            printf("-1\n");
    }
    else
        printf("-1\n");
}