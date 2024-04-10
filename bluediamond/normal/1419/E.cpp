#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));

#define x first
#define f second

int n;
vector<int> opt;
vector<int> ord;
vector<int> d;
vector<vector<int>> good;
vector<bool> need;
bool found;

void dfs(int now, int len)
{
    if (found == 1)
    {
        return;
    }
    if (len == n)
    {
        found = 1;
        opt = ord;
        opt.push_back(d[now]);
        return;
    }
    need[now] = 1;
    ord.push_back(d[now]);
    for (auto &y : good[now])
    {
        if (need[y] == 0)
        {
            dfs(y, len + 1);
        }
    }
    ord.pop_back();
    need[now] = 0;
}

vector<int> dumb()
{
        found = 0;
        d.clear();
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i > 1)
                {
                    d.push_back(i);
                }
                if (i * i != n)
                {
                    d.push_back(n / i);
                }
            }
        }
        sort(d.begin(), d.end());
        n = (int) d.size();
        need.clear();
        need.resize(n, 0);
        good.clear();
        good.resize(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(d[i], d[j]) > 1)
                {
                    good[i].push_back(j);
                    good[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            shuffle(good[i].begin(), good[i].end(), rng);
        }
        opt = {-1};
        dfs(n - 1, 1);
       return opt;
}

bool only(int cur, int x)
{
    if (cur == 1)
    {
        return 1;
    }
    else
    {
        if (cur % x)
        {
            return 0;
        }
        else
        {
            return only(cur / x, x);
        }
    }
}

vector<int> solve(vector<pair<int, int>> d)
{
    if ((int) d.size() <= 3)
    {
        n = 1;
        for (auto &it : d)
        {
            for (int j = 1; j <= it.f; j++)
            {
                n *= it.x;
            }
        }
        return dumb();
    }
    pair<int, int> it = d.back();
    d.pop_back();
    vector<int> aux = solve(d), sol;
    int cur = 1;
    for (int j = 1; j <= it.f; j++)
    {
        cur *= it.x;
    }
    for (int j = it.f; j >= 1; j--)
    {
        for (auto &x : aux)
        {
            sol.push_back(x * cur);
        }
        cur /= it.x;
    }
    cur = 1;
    for (int j = 1; j <= it.f; j++)
    {
        cur *= it.x;
        sol.push_back(cur);
    }
    for (int i = 1; i < (int) sol.size(); i++)
    {
        if (!only(sol[i], it.x))
        {
            swap(sol[i], sol.back());
        }
    }
    for (auto &x : aux)
    {
        sol.push_back(x);
    }
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    /// have some drip like me

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> d;
        for (int i = 2; i * i <= n; i++)
        {
            int c = 0;
            while (n % i == 0)
            {
                c++;
                n /= i;
            }
            if (c)
            {
                d.push_back({i, c});
            }
        }
        if (n > 1)
        {
            d.push_back({n, 1});
        }
        if ((int) d.size() == 2 && d[0].f == 1 && d[1].f == 1)
        {
            cout << d[0].x << " " << d[0].x * d[1].x << " " << d[1].x << "\n";
            cout << "1\n";
            continue;
        }
        vector<int> sol = solve(d);
        for (auto &x : sol)
        {
            cout << x << " ";
        }
        cout << "\n";
        cout << "0\n";
    }
}