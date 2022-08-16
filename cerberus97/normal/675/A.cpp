#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, d, n;
    cin >> a >> b >> d;

    if (d)
        n = (b - a)/d;

    if (!d and a == b)
        cout << "YES";

    else if (!d and a != b)
        cout << "NO";

    else if (n >= 0 and int(fabs(b - a)) % int(fabs(d)) == 0)
        cout << "YES";

    else
        cout << "NO";


}