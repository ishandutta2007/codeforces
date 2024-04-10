#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    d = min(b, a + c) + min(c + a, b + a + a);
    cout << d;
    return 0;
}