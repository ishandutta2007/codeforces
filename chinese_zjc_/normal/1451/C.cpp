//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n, T, k, has[50];
string a, b, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> a >> b;
        fill(has, has + 50, 0);
        for (int i = 0; i < a.length(); ++i)
        {
            ++has[a[i] - 'a'];
        }
        for (int i = 0; i < b.length(); ++i)
        {
            --has[b[i] - 'a'];
        }
        ans = "Yes";
        for (int i = 0; i < 26; ++i)
        {
            if (has[i] % k)
            {
                ans = "No";
                break;
            }
            has[i] /= k;
        }
        if (ans == "No")
        {
            cout << ans << endl;
            continue;
        }
        int tmp = 0;
        for (int i = 25; i >= 0; --i)
        {
            tmp += has[i];
            if (tmp > 0)
            {
                ans = "No";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}