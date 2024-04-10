#include <bits/stdc++.h>

using namespace std;

int go[(int)3e5 * 31 + 10][2];
int sum[(int)3e5 * 31 + 10];
int cnt = 1;

void add(int x, int y)
{
    int v = 0;
    for (int i = 29; i >= 0; i--)
    {
        int t = 0;
        if (x & (1 << i))
            t = 1;
        if (go[v][t] == -1)
        {
            go[v][t] = cnt;
            cnt++;
        }
        v = go[v][t];
        sum[v] += y;
    }
}

int a[(int)3e5 + 10], b[(int)3e5 + 10];

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < (int)3e5 * 31 + 10; i++)
        fill(go[i], go[i] + 2, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        add(b[i], 1);
    }
    for (int i = 0; i < n; i++)
    {
        int v = 0;
        int s = 0;
        for (int j = 29; j >= 0; j--)
        {
            int t = 0;
            if (a[i] & (1 << j))
                t = 1;
            if (go[v][t] != -1 && sum[go[v][t]] > 0)
            {
                v = go[v][t];
                s += t * (1 << j);
            }
            else
            {
                v = go[v][1 - t];
                s += (1 - t) * (1 << j);
            }
        }
        cout << (a[i] ^ s) << " ";
        add(s, -1);
    }
    cout << endl;
    return 0;
}