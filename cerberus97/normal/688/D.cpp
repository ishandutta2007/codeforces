#include <iostream>
#include <cmath>

using namespace std;

bool known[1000005] = {0};
int c[1000005];

int gcd(int a, int b)
{
    if (!b)
        return a;

    return gcd(b, a%b);
}

void calc(int n, int k)
{
    for (int i = 0; i < n; ++i)
    {
        if (known[c[i]] or gcd(c[i], k) == 1)
            continue;

        known[c[i]] = true;

        int sq = sqrt(c[i]);

        for (int j = 2; j <= sq; ++j)
        {
            if (c[i] % j == 0)
            {
                known[j] = true;
                known[c[i]/j] = true;
            }
        }

        if (known[k])
            return;
    }
}

bool check (int k)
{
    if (known[k])
        return true;

    int sq = sqrt(k), temp = k;

    for (int i = 2; i <= sq; ++i)
    {
        if (temp % i == 0)
        {
            int x = 1;

            while (temp % i == 0)
            {
                temp /= i;
                x *= i;
            }

            if (!known[x])
                return false;

        }
    }

    return known[temp];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    known[1] = true;

    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        //known[c[i]] = true;

        if (c[i] % k == 0)
            known[k] = true;
    }

    if (known[k])
    {
        cout << "Yes";
        return 0;
    }

    calc(n, k);

    if (check(k))
        cout << "Yes";

    else
        cout << "No";
}