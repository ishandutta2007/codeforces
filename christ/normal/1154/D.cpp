#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b, a;
    scanf("%i%i%i", &n, &b, &a);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int cb = b, ca = a;
    for (int x = 0; x < n; x++)
    {
        if (!b && !a)
            return 0 * printf("%i\n", x);
        if (!b)
            a--;
        else if (!a)
            b--, a += arr[x];
        else
        {
            if (arr[x])
            {
                if (a == ca)
                    a--;
                else
                    b--, a++;
            }
            else
                a--;
        }
    }
    printf("%i\n", n);
}