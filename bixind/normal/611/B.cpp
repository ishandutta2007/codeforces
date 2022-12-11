#include <iostream>


using namespace std;

int main()
{
    long long a, b, i, j, n, k1, k2;
    cin >> a >> b;
    int cnt = 0;
    n = 1;
    for (i = 1; i < 63; i++)
    {
        n *= 2;
        n--;
        k1 = 1;
        for (j = 0; j < i - 1; j++)
        {
            if ((n - k1) >= a && (n - k1) <= b)
                cnt++;
            k1 *= 2;
        }
        n++;
    }
    cout << cnt;
    return 0;
}