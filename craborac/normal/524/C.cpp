#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

long long mas[(int)5e3 + 10];

int main()
{
    unordered_set<int> us;
    //freopen("c.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
        us.insert(mas[i]);
    }
    int m;
    cin >> m;
    for (int qwe = 0; qwe < m; qwe++)
    {
        long long c;
        cin >> c;
        int ans = 300;
        for (int i = 0; i < n; i++)
        {
            if (k * mas[i] >= c)
            {
                for (int q = 1; q <= k; q++)
                {
                    long long d = c - mas[i] * q;
                    if (d == 0)
                    {
                        ans = min(ans, q);
                    }
                    else if (d > 0)
                    {
                        for (int w = 1; q + w <= k; w++)
                        {
                            if (d % w == 0)
                            {
                                if (us.find(d / w) != us.end())
                                {
                                    ans = min(ans, q + w);
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (ans == 300)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}