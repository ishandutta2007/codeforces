#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200 + 7;
int n;
int a[N];
int b[N];
string s;

void solve(int x)
{
    vector<int> ops;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != x)
        {
            ops.push_back(i);
            a[i] ^= 1;
            a[i + 1] ^= 1;
        }
    }
    bool good = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != x)
        {
            good = 0;
        }
    }
    if (good)
    {
        cout << (int) ops.size() << "\n";
        for (auto &i : ops)
        {
            cout << i << " ";
        }
        cout << "\n";
        exit(0);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] =  (s[i - 1] == 'W');
    }
    solve(0);
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i];
    }
    solve(1);
    cout << "-1\n";
}