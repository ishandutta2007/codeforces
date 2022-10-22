#include <bits/stdc++.h>

using namespace std;

bool startswith(string &a, string &b)
{
    for (int x = 0; x < a.length(); x++)
        if (a[x] != b[x])
            return 0;
    return 1;
}

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.first.length() < b.first.length();
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    vector<pair<string, int>> arr(2 * n - 2);
    for (int x = 0; x < 2 * n - 2; x++)
    {
        cin>>arr[x].first;
        arr[x].second = x;
    }
    sort(arr.begin(), arr.end(), cmp);
    string cur = arr.back().first;
    vector<int> has(n, -1);
    vector<string> unused;
    int cnt = 0;
    for (auto &x : arr)
    {
        if (!~has[x.first.length()] && startswith(x.first, cur))
            has[x.first.length()] = x.second, cnt++;
        else
            unused.push_back(x.first);
    }
    vector<char> pre(2 * n - 2);
    if (cnt == n-1)
    {
        for (auto &x : unused)
            reverse(x.begin(), x.end());
        sort(unused.begin(), unused.end(), [&](string &a, string &b){
            return a.length() < b.length();
        });
        for (int x = 1; x < n-1; x++)
            if (!startswith(unused[x-1], unused[x]))
                cnt = 0;
    }
    if (cnt == n-1)
    {
        for (int x = 1; x < n; x++)
            pre[has[x]] = 1;
    }
    else
    {
        cur = arr[arr.size() - 2].first;
        fill(has.begin(), has.end(), -1);
        cnt = 0;
        for (auto &x : arr)
        {                                                          
            if (!~has[x.first.length()] && startswith(x.first, cur))
                has[x.first.length()] = x.second, cnt++;
        }
        if (cnt == n-1)
        {
            for (int x = 1; x < n; x++)
                pre[has[x]] = 1;
        }
        else
            abort();
    }
    for (auto &x : pre)
        printf("%c", x ? 'P' : 'S');
}