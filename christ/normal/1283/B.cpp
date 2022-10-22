#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n, k;
        scanf("%i%i", &n, &k);
        int tt = n / k;
        int left = n % k;
        printf("%i\n", tt * k + min(k / 2, left));
    }
}