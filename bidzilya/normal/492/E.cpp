#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, dx, dy;

    cin >> n >> m >> dx >> dy;

    int a = n - dy;
    int b = dx;

    unordered_map<int, int> mp;

    int ans = 0;
    int ans_x = 0;
    int ans_y = 0;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        int c = (1LL * x * a + 1LL * y * b) % n;
        c = n - c;

        int& val = mp[c];

        ++val;

        if (val > ans) {
            ans = val;
            ans_x = x;
            ans_y = y;
        }
    }

    cout << ans_x << " " << ans_y << endl;

    return 0;
}