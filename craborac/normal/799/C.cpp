#include <bits/stdc++.h>
#define android ios

using namespace std;

vector<pair<int, int> > v1, v2;
int a[(int)1e5 + 10], b[(int)1e5 + 10];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'C')
        {
            if (b <= x)
            {
                v1.push_back({b, a});
                s1 = max(s1, a);
            }
        }
        else
        {
            if (b <= y)
            {
                v2.push_back({b, a});
                s2 = max(s2, a);
            }
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = 0;
    if (s1 > 0 && s2 > 0)
        ans = s1 + s2;
    if (v1.size() > 1)
    {
        int w = v1.size() - 1;
        a[0] = v1[0].second;
        b[0] = 0;
        for (int i = 1; i < v1.size(); i++)
        {
            if (v1[i].second > a[i - 1])
            {
                b[i] = a[i - 1];
                a[i] = v1[i].second;
            }
            else if (v1[i].second > b[i - 1])
            {
                a[i] = a[i - 1];
                b[i] = v1[i].second;
            }
            else
            {
                a[i] = a[i - 1];
                b[i] = b[i - 1];
            }
        }
        for (int i = 0; i < v1.size(); i++)
        {
            while (w >= 0 && v1[i].first + v1[w].first > x)
                w--;
            if (w >= 0)
            {
                //ans = max(ans, v1[i].second + )
                if (a[w] == v1[i].second)
                    ans = max(ans, v1[i].second + b[w]);
                else
                    ans = max(ans, v1[i].second + a[w]);
            }
        }
    }

    if (v2.size() > 1)
    {
        int w = v2.size() - 1;
        a[0] = v2[0].second;
        b[0] = 0;
        for (int i = 1; i < v2.size(); i++)
        {
            if (v2[i].second > a[i - 1])
            {
                b[i] = a[i - 1];
                a[i] = v2[i].second;
            }
            else if (v2[i].second > b[i - 1])
            {
                a[i] = a[i - 1];
                b[i] = v2[i].second;
            }
            else
            {
                a[i] = a[i - 1];
                b[i] = b[i - 1];
            }
        }
        for (int i = 0; i < v2.size(); i++)
        {
            while (w >= 0 && v2[i].first + v2[w].first > y)
                w--;
            if (w >= 0)
            {
                //ans = max(ans, v2[i].second + )
                if (a[w] == v2[i].second)
                    ans = max(ans, v2[i].second + b[w]);
                else
                    ans = max(ans, v2[i].second + a[w]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}