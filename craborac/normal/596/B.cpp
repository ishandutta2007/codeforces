#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long last = 0, a, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ans += abs(a - last);
        last = a;
    }
    cout << ans << endl;
    return 0;
}