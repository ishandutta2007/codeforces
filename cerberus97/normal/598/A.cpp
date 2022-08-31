#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    long long n, a, b, c;

    cin >> t;

    while (t--)
    {
        cin >> n;

        a = n * (n + 1) / 2;

        b = log2(n);

        c = pow(2, b + 2) - 2;

        cout << a - c << '\n';

    }

    return 0;

}