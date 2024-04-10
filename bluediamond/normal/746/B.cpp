#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        t += "?";
    }
    int l = n / 2 + 1, r = n / 2;
    l--;
    r--;
    for (int i = 0; i < n; i++)
    {
        if ((n - i) % 2 == 0)
        {
            t[--l] = s[i];
        }
        else
        {
            t[++r] = s[i];
        }
    }
    cout << t << "\n";
}