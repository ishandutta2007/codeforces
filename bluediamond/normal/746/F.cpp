#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
int w;
int k;
int a[N];
int t[N];
set<pair<int, int>> half;
set<pair<int, int>> full;
int cost;

void add(int i)
{
    if ((int) half.size() < w)
    {
        half.insert({t[i], i});
        cost += (t[i] + 1) / 2;
        return;
    }
    auto it = *half.begin();
    if (t[i] > it.first)
    {
        half.erase(it);
        cost -= (it.first + 1) / 2;
        full.insert(it);
        cost += it.first;
        half.insert({t[i], i});
        cost += (t[i] + 1) / 2;
    }
    else
    {
        full.insert({t[i], i});
        cost += t[i];
    }
}

void del(int i)
{
    if (half.count({t[i], i}))
    {
        half.erase({t[i], i});
        cost -= (t[i] + 1) / 2;
        if ((int) half.size() < w && !full.empty())
        {
            auto it = full.end();
            it--;
            cost -= it->first;
            cost += (it->first + 1) / 2;
            full.erase(it);
            half.insert(*it);
        }
    }
    else
    {
        full.erase({t[i], i});
        cost -= t[i];
    }
}

int brute(int l, int r)
{
    vector<int> e;
    for (int i = l; i <= r; i++)
    {
        e.push_back(t[i]);
    }
    sort(e.rbegin(), e.rend());
    int cost = 0;
    for (int i = 0; i < (int) e.size(); i++)
    {
        if (i < w)
        {
            cost += (e[i] + 1) / 2;
        }
        else
        {
            cost += e[i];
        }
    }
    return cost;
}

int cost2()
{
    int sol = 0;
    for (auto &it : half)
    {
        sol += (it.first + 1) / 2;
    }
    for (auto &it : full)
    {
        sol += it.first;
    }
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    int p = 0, sol = 0;
    for (int i = 1; i <= n; i++)
    {
        while (p < n)
        {
            p++;
            add(p);
            if (cost > k)
            {
                del(p);
                p--;
                break;
            }
        }
        sol = max(sol, a[p] - a[i - 1]);
        del(i);
    }
    cout << sol << "\n";
}