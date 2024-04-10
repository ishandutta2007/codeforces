#include <bits/stdc++.h>

using namespace std;

bool cmp(string &a, string &b)
{
    return a.length() < b.length();
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<string> arr(n);
    for (auto &x : arr)
        cin >> x;
    sort(arr.begin(), arr.end(), cmp);
    for (int x = 1; x < n; x++)
        if (arr[x].find(arr[x-1]) == string::npos)
            return 0 * printf("NO\n");
    printf("YES\n");
    for (auto &x : arr)
        printf("%s\n", x.c_str());
}