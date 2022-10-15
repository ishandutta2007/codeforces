#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, p[N];
vector<int> g[N];
int sub[N];
double o[N];

void xoxo(int a)
{
    sub[a] = 1;
    for (auto &b : g[a])
    {
        xoxo(b);
        sub[a] += sub[b];
    }
}

void compute(int a)
{
    if (a == 1)
    {
        o[a] = 1;
    }
    else
    {
        o[a] = o[p[a]] + 1 + (sub[p[a]] - 1 - sub[a]) * 0.5;
    }
    for (auto &b : g[a])
    {
        compute(b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    xoxo(1);
    o[0] = 1;
    compute(1);
    for (int i = 1; i <= n; i++)
    {
        cout << o[i] << " ";
    }
    cout << "\n";

}