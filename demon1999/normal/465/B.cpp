#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    long k = -1, p = 0, n, i, c, cpr = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> c;
        if(c == 1)k++;
        if(c == 1&&cpr == 0)k++;
        cpr = c;
    }
    if(k < 0)k = 0;
    cout << k;
    return 0;
}