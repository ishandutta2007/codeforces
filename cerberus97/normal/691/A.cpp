#include <iostream>

using namespace std;

bool a[1005];

bool check(int n)
{
    if (n == 1)
        return a[0];

    int ctr = 0;

    for (int i = 0; i < n; ++i)
        if (!a[i])
            ++ctr;

    return (ctr == 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (check(n))
        cout << "YES";

    else
        cout << "NO";

    return 0;
}