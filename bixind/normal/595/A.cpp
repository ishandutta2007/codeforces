#include <iostream>

using namespace std;

int main()
{
    int i, j, a, b, n, m, ans = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >>a >> b;
            ans += (a | b);
        }
    cout << ans;
    return 0;
}