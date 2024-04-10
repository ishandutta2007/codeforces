#include <bits/stdc++.h>

using namespace std;

int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int f(int x)
{
    if (x <= 9)
    {
        return c[x];
    }
    else
    {
        return f(x / 10) + c[x % 10];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r;
    int ans = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        ans += f(i);
    }
    cout << ans << "\n";

}