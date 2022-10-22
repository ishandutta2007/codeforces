#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    string s;
    cin>>s;
    vector<bool> good(300);
    while (k--)
    {
        char c;
        scanf(" %c", &c);
        good[c] = 1;
    }
    vector<int> cnts;
    int prev = 0;
    for (int y = 0; y < n; y++)
    {
        if (good[s[y]])
            prev++;
        else if (prev)
            cnts.push_back(prev), prev = 0;
    }
    cnts.push_back(prev);
    long long ans = 0;
    for (auto &x : cnts)
        ans += (long long)x * (x + 1) / 2;
    printf("%lli\n", ans);
}