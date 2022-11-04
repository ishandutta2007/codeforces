#include <bits/stdc++.h>
#define android ios

using namespace std;

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<long long> v;
    v.push_back(l - 1);
    v.push_back(r + 1);
    long long a = 1;
    while (true)
    {
        long long b = 1;
        while (true)
        {
            if (l <= a + b && a + b <= r)
                v.push_back(a + b);
            if (r / b >= y)
                b *= y;
            else
                break;
        }
        if (r / a >= x)
            a *= x;
        else
            break;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i + 1 < v.size(); i++)
        ans = max(ans, v[i + 1] - v[i] - 1);
    cout << ans << endl;
    return 0;
}