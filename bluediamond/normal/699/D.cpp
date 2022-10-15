#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
int n;
int p[N];
bool vis[N];
bool act[N];
bool on[N];
bool out;
vector<int> cy;

void inspect(int a)
{
    vis[a] = act[a] = 1;
    int b = p[a];
    if (vis[b] == 0)
    {
        inspect(b);
    }
    else
    {
        if (act[b])
        {
            cy.push_back(b);
        }
    }
    act[a] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            inspect(i);
        }
    }
    int pos = 0, sz = (int) cy.size();
    for (int i = 0; i < sz; i++)
    {
        if (p[cy[i]] == cy[i])
        {
            pos = cy[i];
        }
    }
    if (pos == 0)
    {
        cout << sz << "\n";
        pos = cy[0];
        p[pos] = pos;
        for (int i = 0; i < sz; i++)
        {
            if (cy[i] != pos)
            {
                p[cy[i]] = pos;
            }
        }
    }
    else
    {
        cout << sz - 1 << "\n";
        for (int i = 0; i < sz; i++)
        {
            if (cy[i] != pos)
            {
                p[cy[i]] = pos;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";

}