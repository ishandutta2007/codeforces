#include <iostream>

using namespace std;

int main()
{
    int n, a[100];

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        bool flag = false;

        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                flag = true;
                swap(a[j], a[j + 1]);
                cout << j + 1 << ' ' << j + 2 << '\n';
            }
        }

        if (!flag)
            break;
    }

    return 0;
}