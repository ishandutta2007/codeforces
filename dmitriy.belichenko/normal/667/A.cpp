#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
using namespace std;
const double PI = acos(-1);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    double d , h , v , e;
    cin >> d >> h >> v >> e;
    v = 4 * v / (d * d *PI);
    double ans = h / (v - e);
    if(ans >= 0)
    {
        cout << "YES\n" << ans << "\n";
        return 0;
    }
    cout << "NO";
    return 0;
}