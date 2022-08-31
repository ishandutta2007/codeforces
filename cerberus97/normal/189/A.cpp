#include <iostream>

using namespace std;

int s[10000001];

int main()
{
    int t, n, a, b, c;

    t = 1;

    while (t--)
    {
        cin >> n >> a >> b >> c;

        s[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            s[i] = -1e9;

            if (i >= a)
                s[i] = s[i - a] + 1;

            if (i >= b)
                s[i] = max(s[i], s[i - b] + 1);

            if (i >= c)
                s[i] = max(s[i], s[i - c] + 1);
        }

        cout << s[n] << '\n';

    }

    return 0;
}