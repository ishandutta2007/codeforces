#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);
        vector<string> arr(n);
        set<string> used;
        set<string> og;
        int k = 0;
        for (auto &x : arr)
        {
            cin>>x;
            og.insert(x);
        }
        for (auto &x : arr)
        {
            if (used.count(x))
            {
                while (og.count(x) || used.count(x))
                    x[0] = (x[0] - '0' + 1) % 10 + '0';
                k++;
            }
            used.insert(x);
        }
        printf("%i\n", k);
        for (auto &x : arr)
            printf("%s\n", x.c_str());
    }
}