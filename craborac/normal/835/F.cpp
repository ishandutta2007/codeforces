#include <bits/stdc++.h>
#define android ios

using namespace std;

int used[(int)2e5 + 10], cir[(int)2e5 + 10];
vector<pair<int, long long> > mas[(int)2e5 + 10];
vector<int> arr;
vector<int> dist;
long long mx[(int)2e5 + 10];
long long pa[(int)2e5 + 10];
long long sa[(int)2e5 + 10];
long long pd[(int)2e5 + 10];
long long sd[(int)2e5 + 10];
long long dd[(int)2e5 + 10];
long long ans1;
int ver, pp;

void dfs(int v, int pr)
{
    used[v] = 1;
    for (auto p: mas[v])
    {
        int u = p.first;
        if (used[u] == 0)
        {
            dfs(u, v);
            if (ver != -1)
            {
                cir[v] = 1;
                arr.push_back(v);
                dist.push_back(p.second);
                if (v == ver)
                    ver = -1;
                return;
            }
        }
        else if (u != pr)
        {
            ver = u;
            cir[v] = 1;
            arr.push_back(v);
            dist.push_back(p.second);
            return;
        }
    }
}

void dfs2(int v)
{
    used[v] = 1;
    mx[v] = 0;
    for (auto p: mas[v])
    {
        int u = p.first;
        if (used[u] == 0 && cir[u] == 0)
        {
            dfs2(u);
            ans1 = max(ans1, mx[v] + mx[u] + p.second);
            mx[v] = max(mx[v], mx[u] + p.second);
        }
    }
}

void dfs3(int v)
{
    used[v] = 1;
    for (auto p: mas[v])
    {
        int u = p.first;
        if (used[u] == 0 && (v != arr[pp] || u != arr[pp + 1]) && (v != arr[pp + 1] || u != arr[pp]))
        {
            dd[u] = dd[v] + p.second;
            dfs3(u);
        }
        else if (used[u] == 0)
        {
            //cerr << v << " " << u << " " << pp << " " << arr[pp] << " " << arr[pp + 1] << " kukarek" << endl;
        }
    }
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        mas[a].push_back({b, c});
        mas[b].push_back({a, c});
    }
    ver = -1;
    fill(used, used + n, 0);
    fill(cir, cir + n, 0);
    dfs(0, -1);
    ans1 = 0;
    fill(used, used + n, 0);
    for (int i: arr)
        dfs2(i);
    dist.push_back(dist[0]);
    long long s = 0;
    long long sum = mx[arr[0]];
    pd[0] = mx[arr[0]];
    pa[0] = (long long)-1e18;
    for (int i = 1; i < arr.size(); i++)
    {
        s += dist[i];
        sum += dist[i];
        pd[i] = max(pd[i - 1], s + mx[arr[i]]);
        pa[i] = max(pa[i - 1], mx[arr[i]] + sum);
        sum = max(sum, mx[arr[i]]);
    }
    sd[arr.size()] = (long long)-1e18;
    sa[arr.size()] = (long long)-1e18;
    s = 0;
    sum = (long long)-1e18;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        s += dist[i + 1];
        sum += dist[i + 1];
        sd[i] = max(sd[i + 1], s + mx[arr[i]]);
        sa[i] = max(sa[i + 1], mx[arr[i]] + sum);
        sum = max(sum, mx[arr[i]]);
    }
    long long ans = (long long)1e18;
    pp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        long long ans2;
        if (i + 1 < arr.size())
            ans2 = max(pd[i] + sd[i + 1], max(pa[i], sa[i + 1]));
        else
            ans2 = pa[i];
        //cerr << arr[i] + 1 << " " << ans2 << "  " << pd[i] << " " << pa[i] << "  " << sd[i + 1] << " " << sa[i + 1] << endl;
        if (ans2 < ans)
        {
            ans = ans2;
            pp = i;
        }
        //ans = min(ans, max(ans1, ans2));
    }
    //cout << pp << " " << ans << endl;
    arr.push_back(arr[0]);
    fill(used, used + n, 0);
    fill(dd, dd + n, 0);
    dfs3(0);
    int v = 0;
    for (int i = 0; i < n; i++)
        if (dd[i] > dd[v])
            v = i;
    fill(used, used + n, 0);
    fill(dd, dd + n, 0);
    dfs3(v);
    for (int i = 0; i < n; i++)
        if (dd[i] > dd[v])
            v = i;
    cout << dd[v] << endl;
    return 0;
}