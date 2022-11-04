#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n;
int q[4010], d[4010], p[4010];

void ko(int v)
{
    for (int i = v + 1; i < n; i++)
    {
        if (p[i] >= 0)
        {
            p[i] -= d[v];
            if (p[i] < 0)
            {
                ko(i);
            }
        }
    }
}

void vr(int v)
{
    vector<int> mas;
    for (int i = v + 1; i < n; i++)
    {
        if (p[i] >= 0)
        {
            p[i] -= q[v];
            q[v]--;
            if (p[i] < 0)
            {
                mas.push_back(i);
            }
        }
        if (q[v] == 0)
            break;
    }
    for (int i = 0; i < mas.size(); i++)
    {
        ko(mas[i]);
    }
}

int main()
{
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i] >> d[i] >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (p[i] >= 0)
        {
            ans.push_back(i);
            vr(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}