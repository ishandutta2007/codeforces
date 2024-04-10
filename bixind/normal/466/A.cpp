#include <iostream>

using namespace std;

int main()
{
    int n, m, b, a, ans;
    cin >> n >> m >> a >> b;
    ans = min((n / m) * b + (n % m) * a, (n / m + 1) * b);
    ans = min(n * a, ans);
    cout << ans;
    return 0;
}