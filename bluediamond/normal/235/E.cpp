#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 3000 + 7;

struct T
{
    int a;
    int b;
    int c;
    int it;
};

bool operator < (T f, T s)
{
    if (f.a != s.a)
    {
        return f.a < s.a;
    }
    if (f.b != s.b)
    {
        return f.b < s.b;
    }
    if (f.c != s.c)
    {
        return f.c < s.c;
    }
    return f.it < s.it;
}

bool prie(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

vector<int> p;
map<T, unsigned int> ret;

unsigned int solve(int a, int b, int c, int it)
{
    if (it == -1)
    {
        return 1;
    }
    vector<int> e = {a, b, c};
    sort(e.begin(), e.end());
    a = e[0];
    b = e[1];
    c = e[2];
    if (ret.count({a, b, c, it}))
    {
        return ret[{a, b, c, it}];
    }
    vector<int> pws = {1, p[it]};
    while (pws.back() < N)
    {
        pws.push_back(pws.back() * p[it]);
    }
    unsigned int sol = 0;
    for (int i = 0; i < (int) pws.size() && pws[i] <= a; i++)
    {
        for (int j = 0; j < (int) pws.size() && pws[j] <= b; j++)
        {
            for (int k = 0; k < (int) pws.size() && pws[k] <= c; k++)
            {
                sol += solve(a / pws[i], b / pws[j], c / pws[k], it - 1) * (i + j + k + 1);
            }
        }
    }
    ret[{a, b, c, it}] = sol;
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++)
    {
        if (prie(i))
        {
            p.push_back(i);
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c, (int) p.size() - 1) % 1073741824 << "\n";
}