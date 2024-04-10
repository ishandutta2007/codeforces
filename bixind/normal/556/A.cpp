#include <iostream>

using namespace std;

int main()
{
    int n, i, z = 0, o = 0;
    char c;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        if (c == '0') z++;
        else o++;
    }
    cout << max(z, o) - min(z, o);
    return 0;
}