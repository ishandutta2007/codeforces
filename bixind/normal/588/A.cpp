#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i;
    long long a, p, mp = 1e9;
    long long ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a >> p;
        mp = min(mp, p);
        ans += mp * a;
    }
    cout << ans;
    return 0;
}