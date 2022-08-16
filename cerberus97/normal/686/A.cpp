#include <iostream>

using namespace std;

int main()
{
    int n;
    char c;
    long long x, d, distr = 0;

    cin >> n >> x;

    for (int i = 0; i < n; ++i)
    {
        cin >> c >> d;

        if (c == '+')
            x += d;

        else
        {
            if (x >= d)
                x -= d;

            else
                distr++;
        }
    }

    cout << x << ' ' << distr;

    return 0;
}