#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> p(n), c(n), id(n+1);
    vector<long long> ans(n);
    vector<int> u;
    for (auto &x : p)
        scanf("%i", &x), u.push_back(x);
    sort(u.begin(), u.end());
    for (auto &x : p)
        x = lower_bound(u.begin(), u.end(), x) - u.begin() + 1;
    for (auto &x : c)
        scanf("%i", &x);
    for (int x = 0; x < n; x++)
        id[p[x]] = x;
    multiset<int> cur;
    long long s = 0;
    for (int x = 1; x <= n; x++)
    {
        ans[id[x]] = s + c[id[x]];
        if (k)
        {
            s += c[id[x]];
            cur.insert(c[id[x]]);
            if (cur.size() > k)
            {
                s -= *cur.begin();
                cur.erase(cur.begin());
            }
        }
    }
    for (auto &x : ans)
        printf("%lli ", x);
}