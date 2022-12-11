#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    long long n, i, n1;
    cin >> n;
    n1 = n;
    set<long long> dl;
    for (i = 2; i <= sqrtl(n) + 10; i++)
    {
        if (n1 <= 1)
            break;
        if (n1 % i == 0)
        {
            dl.insert(i);
            while (n1 % i == 0)
            {
                n1 /= i;
            }
        }
    }
    if (n1 > 1)
        dl.insert(n1);
    long long ans = 1;
    for (auto w : dl)
        ans *= w;
    cout << ans;
    return 0;
}