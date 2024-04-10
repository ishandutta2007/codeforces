#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    long k = 0, p = 0, n, i;
    char c;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        if(p == 0)k++;
        cin >> c;
        if(c == '0')p = 1;
    }
    cout << k;
    return 0;
}