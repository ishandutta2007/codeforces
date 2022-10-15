#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n, mx;
int s[N];
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mx;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + 1 - a[i];
    }
    int l = 1, ans = 0, pl, pr;
    for (int r = 1; r <= n; r++)
    {
        while (s[r] - s[l - 1] > mx)
        {
            l++;
        }
        if (ans < r - l + 1)
        {
            ans = r - l + 1;
            pl = l;
            pr = r;
        }
    }
    for (int i = pl; i <= pr; i++)
    {
        a[i] = 1;
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

}