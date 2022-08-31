#include <iostream>

using namespace std;

int main()
{
    int n, d, ans = 0, cur = 0;
    bool flag;
    char sched[105][105];

    cin >> n >> d;

    for (int i = 1; i <= d; ++i)
    {
        flag = false;

        for (int j = 1; j <= n; ++j)
        {
            cin >> sched[i][j];

            if (sched[i][j] == '0')
                flag = true;
        }

        if (flag)
        {
            ++cur;
            ans = max(ans, cur);
        }

        else
            cur = 0;
    }

    cout << ans;
}