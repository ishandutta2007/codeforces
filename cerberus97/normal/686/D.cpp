#include <iostream>
#include <vector>

using namespace std;

vector <int> g[300005];
int p[300005], sub[300005], cent[300005], largestSub[300005], largestSubSize[300005];

void calcSub(int cur)
{
    sub[cur] = 1;
    largestSub[cur] = cur;
    largestSubSize[cur] = 0;

    for (vector <int>::iterator i = g[cur].begin(); i != g[cur].end(); ++i)
    {
        calcSub(*i);
        sub[cur] += sub[*i];

        if (sub[*i] > largestSubSize[cur])
        {
            largestSubSize[cur] = sub[*i];
            largestSub[cur] = *i;
        }
    }
}

void calcCentroids(int cur)
{
    if (g[cur].empty())
    {
        cent[cur] = cur;
        return;
    }

    for (vector <int>::iterator i = g[cur].begin(); i != g[cur].end(); ++i)
    {
        calcCentroids(*i);
    }

    if (largestSubSize[cur] <= sub[cur]/2)
    {
        cent[cur] = cur;
        return;
    }

    int start = cent[largestSub[cur]];

    while (sub[cur] - sub[start] > sub[cur]/2)
    {
        start = p[start];
    }

    cent[cur] = start;
}

int main()
{
    int n, q, x;
    cin >> n >> q;

    for (int i = 2; i <= n; ++i)
    {
        cin >> x;
        p[i] = x;
        g[x].push_back(i);
    }

    calcSub(1);
    calcCentroids(1);

    for (int i = 0; i < q; ++i)
    {
        cin >> x;
        cout << cent[x] << '\n';
    }
}