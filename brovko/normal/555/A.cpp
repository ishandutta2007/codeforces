#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int x = 0;

    for(int i = 0; i < k; i++)
    {
        int m;
        cin >> m;

        int F = 0;

        for(int j = 0; j < m; j++)
        {
            int a;
            cin >> a;

            if(a == 1)
                F++;
            else
            if(F > 0 && a == j + 1)
                F++;
        }

        x += F;
    }

    cout << k - 1 + 2 * (n - k) - 2 * (x - 1);
}