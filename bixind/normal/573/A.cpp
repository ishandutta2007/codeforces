#include <iostream>

using namespace std;

int main()
{
    int n, k, i, pr;
    cin >> n;
    cin >> k;
    while (k % 3 == 0)
        k /= 3;
    while (k % 2 == 0)
        k /= 2;
    pr = k;
    for (i = 1; i < n; i++)
    {
        cin >> k;
        while (k % 3 == 0)
            k /= 3;
        while (k % 2 == 0)
            k /= 2;
        if (k != pr)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}