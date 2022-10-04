/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair

using namespace std;

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c;
    for (int i = 1; i < 1000; ++i) {
        if ((i > a) || (i * 2 > b) || (i * 4 > c)) {
            x = i - 1;
            break;
        }
    }
    cout << 7 * x;
    return 0;
}