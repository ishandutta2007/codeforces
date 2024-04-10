#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int last = -1;
        int fir = -1;
        int col1 = 0, q = 2;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            if (fir == -1)
            {
                fir = a;
            }
            if (a != last + 1)
            {
                q = max(0, q - 1);
            }
            last = a;
            col1 += q;
        }
        ans += k - 1;
        if (fir == 1)
        {
            ans -= 2 * (col1 - 1);
        }
    }
    cout << ans + n - 1 << endl;
    return 0;
}