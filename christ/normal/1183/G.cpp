#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<pair<int, int>> a(MAXN), pre;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n;
        scanf("%i", &n);
        for (int x = 0; x < n; x++)
            scanf("%i%i", &a[x].first, &a[x].second);
        sort(a.begin(), a.begin() + n);
        pre.clear();
        int cnt0 = 0, cnt1 = 0;
        for (int lst = -1, x = 0; x < n; x++)
        {
            if (lst != a[x].first)
            {
                pre.push_back({cnt0 + cnt1, cnt1});
                cnt0 = 0, cnt1 = 0;
                lst = a[x].first;
            }
            if (a[x].second)
                cnt1++;
            else
                cnt0++;
        }
        pre.push_back({cnt0 + cnt1, cnt1});
        sort(pre.begin(), pre.end());
        int ans0 = 0, ans1 = 0;
        priority_queue<int> buf;
        int m = pre.size();
        for (int lst = pre[m - 1].first, x = m - 1; lst > 0; )
        {
            if (buf.empty())
                lst = pre[x].first;
            while (x > 0 && lst == pre[x].first)
                buf.push(pre[x--].second);
            ans0 += lst;
            ans1 += min(lst, buf.top());
            buf.pop();
            lst--;
        }
        printf("%i %i\n", ans0, ans1);
    }
}