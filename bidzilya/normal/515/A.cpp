#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int a, b, s;
    cin >> a >> b >> s;

    if (abs(a) + abs(b) <= s && (abs(a) + abs(b)) % 2 == s % 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}