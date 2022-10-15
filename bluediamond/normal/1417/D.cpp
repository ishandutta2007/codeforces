#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int t;
int n;
int s;
int x;
int a[N];

struct T
{
    int i;
    int j;
    int x;
};

vector<T> sol;

void op(int i, int j, int x)
{
    sol.push_back({i, j, x});
    a[i] -= x * i;
    a[j] += x * i;
    if (a[i] < 0)
    {
        cout << "error at op\n";
        exit(0);
    }
}

void solve()
{
    int x = s / n;
    sol.clear();
    for (int i = 2; i <= n; i++)
    {
        if (a[i] % i == 0)
        {
            op(i, 1, a[i] / i);
            continue;
        }
        int need = i - a[i] % i;
        op(1, i, need);
        op(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; i++)
    {
        op(1, i, x);
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[1])
        {
            cout << "-1\n";
            return;
        }
    }
    cout << (int) sol.size() << "\n";
    for (auto &it : sol)
    {
        cout << it.i << " " << it.j << " " << it.x << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if (s % n)
        {
            cout << "-1\n";
            continue;
        }
        solve();
    }
}