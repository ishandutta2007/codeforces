#include <iostream>


using namespace std;

int main()
{
    long long x, y, b, n, i, c;
    x = 0;
    cin >> n >> b;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        x = x * b + c;
    }
    y = 0;
    cin >> n >> b;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        y = y * b + c;
    }
//    cout << x << ' ' << y << endl;
    if (x < y)
    {
        cout << '<' << endl;
        return 0;
    }
    if (x > y)
    {
        cout << '>' << endl;
        return 0;
    }
    if (x == y)
    {
        cout << '=' << endl;
        return 0;
    }
    return 0;
}