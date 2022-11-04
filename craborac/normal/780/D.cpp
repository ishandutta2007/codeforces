#include <bits/stdc++.h>

using namespace std;

string ans[1010], s[1010], t[1010];
int used[2010];
vector<int> v, mas[2010];

void dfs(int a)
{
    used[a] = 1;
    for (int u: mas[a])
    {
        if (used[u] == 0)
            dfs(u);
    }
    v.push_back(a);
}

void go(int a)
{
    for (int u: mas[a])
    {
        string b;
        if (u % 2)
            b = t[u / 2];
        else
            b = s[u / 2];
        if (ans[u / 2] == "")
        {
            ans[u / 2] = b;
            go(u);
        }
        else if (ans[u / 2] != b)
        {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

void dfs2(int a)
{
    used[a] = 1;
    for (int b: mas[a])
    {
        if (used[b] == 0)
            dfs2(b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        ans[i] = "";
        //s[i] = "" + a[0] + a[1] + a[2];
        s[i] = "";
        s[i] += a[0];
        s[i] += a[1];
        s[i] += a[2];
        //t[i] = "" + a[0] + a[1] + b[0];
        t[i] = "";
        t[i] += a[0];
        t[i] += a[1];
        t[i] += b[0];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j && s[i] == s[j])
            {
                mas[2 * i].push_back(2 * i + 1);
                break;
            }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (s[i] == t[j])
                    mas[2 * i].push_back(2 * j);
                if (t[i] == s[j])
                    mas[2 * i + 1].push_back(2 * j + 1);
                if (t[i] == t[j])
                    mas[2 * i + 1].push_back(2 * j);
            }
        }
    }
    fill(used, used + 2 * n, 0);
    fill(ans, ans + n, "");
    for (int i = 0; i < 2 * n; i++)
        if (used[i] == 0)
            dfs(i);
    for (int i = 0; i < 2 * n; i++)
    {
        if (ans[v[i] / 2] == "")
        {
            fill(used, used + 2 * n, 0);
            dfs2(v[i]);
            if (used[v[i] ^ 1])
            {
                cout << "NO" << endl;
                return 0;
            }
            if (v[i] % 2)
                ans[v[i] / 2] = t[v[i] / 2];
            else
                ans[v[i] / 2] = s[v[i] / 2];
            go(v[i]);
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}