#include <iostream>

using namespace std;

int main()
{
    int n, i, c, s;
    cin >> n;
    cin >> s;
    c = (n - s) % n;
    for (i = 1; i < n; i++)
    {
        cin >> s;
        if ((s + c*(i % 2 == 0 ? 1 : -1) + n) % n != i)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}