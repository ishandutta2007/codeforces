#include <iostream>
#include <map>

using namespace std;

map <long long, long long> m;
int ctr = 0;

long long getPathCost(long long u, long long v)
{
    long long ans = 0;

    while (u != v)
    {
        if (v < u)
            swap(u, v);

        if (m.find(v) != m.end())
            ans += m[v];

        v /= 2;
    }

    return ans;
}

void update(long long u, long long v, long long w)
{
    while (u != v)
    {
        if (v < u)
            swap(u, v);

        if (m.find(v) == m.end())
            m[v] = 0;

        m[v] += w;
        v /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int q, t;
    long long u, v, w;

    cin >> q;

    while (q--)
    {
        cin >> t;

        if (t == 1)
        {
            cin >> u >> v >> w;

            if (v < u)
                swap(u, v);

            update(u, v, w);
        }

        else
        {
            cin  >> u >> v;
            cout << getPathCost(u, v) << '\n';
        }
    }

    return 0;
}