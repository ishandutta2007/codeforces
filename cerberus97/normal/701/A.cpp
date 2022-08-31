#include <iostream>

using namespace std;

int a[100];
bool seen[100] = {0};

int main()
{
    ios_base::sync_with_stdio(false);

    int n, sum = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    int each = sum*2/n;

    for (int i = 0, j = 0; i < n and j < n/2; ++i)
    {
        while (seen[i])
            ++i;

        seen[i] = true;
        cout << i+1 << ' ';

        int rem = each - a[i], pos = i+1;

        for (; a[pos] != rem or seen[pos]; ++pos);

        cout << pos+1 << '\n';
        seen[pos] = true;

        ++j;
    }

    return 0;
}