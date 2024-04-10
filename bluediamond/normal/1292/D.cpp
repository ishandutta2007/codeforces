#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int K = 5000 + 7;
int n;
int f[K];
int e[K][K];
int value[K];

bool ip(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else
    {
        for (int d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

vector<int> p;

int vp(int i, int d)
{
    int cnt = 0;
    i /= d;
    while (i)
    {
        cnt += i;
        i /= d;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        f[k]++;
    }
    for (int i = 1; i < K; i++)
    {
        if (ip(i))
        {
            p.push_back(i);
        }
    }
    for (int i = 1; i < K; i++)
    {
        for (int j = 0; j < (int) p.size(); j++)
        {
            e[i][j] = vp(i, p[j]);
        }
    }
    ll sum = 0;
    for (int x = 1; x < K; x++)
    {
        ll pentru = 0;
        for (int j = 0; j < (int) p.size(); j++)
        {
            pentru += e[x][j];
        }
        sum += pentru * f[x];
    }
    vector<int> relevant;
    for (int x = 1; x < K; x++)
    {
        relevant.push_back(x);
    }
    while (1)
    {
        map<int, int> fr;
        for (auto &x : relevant)
        {
            value[x] = -1;
            for (int j = (int) p.size() - 1; j >= 0; j--)
            {
                if (e[x][j])
                {
                    value[x] = j;
                    e[x][j]--;
                    fr[j] += f[x];
                    break;
                }
            }
        }
        int mx_fr = 0, who = -1;
        for (auto &it : fr)
        {
            mx_fr = max(mx_fr, it.second);
            if (it.second == mx_fr)
            {
                who = it.first;
            }
        }
        if (n - 2 * mx_fr >= 0)
        {
            break;
        }
        sum += n - 2 * mx_fr;
        vector<int> nw;
        for (auto &x : relevant)
        {
            if (value[x] == who)
            {
                nw.push_back(x);
            }
        }
        relevant = nw;
    }
    cout << sum << "\n";
}