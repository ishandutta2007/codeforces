#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<utility>
#include<vector>

using namespace std;

set<pair<long long, int> > q;
vector<pair<int, int> > mas[(int)1e5 + 10];
int from[(int)1e5 + 10];
int ans[(int)1e5 + 10];
long long d[(int)1e5 + 10];

int main()
{
    int n, m;
    cin >> n >>  m;
    for (int i = 0; i < n; i++)
        d[i] = (long long)1e11 + 10;
    d[0] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        mas[a].push_back(make_pair(b, c));
        mas[b].push_back(make_pair(a, c));
    }
    q.insert(make_pair(0, 0));
    from[0] = -1;
    while (q.size() > 0)
    {
        pair<long long, int> p = *(q.begin());
        q.erase(p);
        int v = p.second;
        for (int i = 0; i < mas[v].size(); i++)
        {
            if (d[v] + mas[v][i].second < d[mas[v][i].first])
            {
                q.erase(make_pair(d[mas[v][i].first], mas[v][i].first));
                d[mas[v][i].first] = d[v] + mas[v][i].second;
                from[mas[v][i].first] = v;
                q.insert(make_pair(d[mas[v][i].first], mas[v][i].first));
            }
        }
    }
    if(d[n - 1] == (long long)1e11 + 10)
    {
        cout << "-1";
        return 0;
    }
    int col = 0;
    int q = n - 1;
    while (q != -1)
    {
        ans[col] = q;
        col++;
        q = from[q];
    }
    for(int i = col - 1; i >= 0; i--)
        cout << ans[i] + 1 << " ";
    return 0;
}